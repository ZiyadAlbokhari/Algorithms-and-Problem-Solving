#include <iostream>

using namespace std;

short ReadDay()
{
	int Day = 0;

	cout << "\nPlease enter a Day? ";
	cin >> Day;

	return Day;
}

short ReadMonth()
{
	int Month = 0;

	cout << "Please enter a Month? ";
	cin >> Month;

	return Month;
}

short ReadYear()
{
	int Year = 0;

	cout << "Please enter a Year? ";
	cin >> Year;

	return Year;
}

struct stDate
{
	short Year = 0;
	short Month = 0;
	short Day = 0;
};

stDate ReadFullDate()
{
	stDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

struct stPeriod
{
	stDate StartDate;
	stDate EndDate;
};

stPeriod ReadPeriod()
{
	stPeriod Period;

	cout << "\nEnter Start Date:\n";
	Period.StartDate = ReadFullDate();

	cout << "\nEnter End Date:\n";
	Period.EndDate = ReadFullDate();

	return Period;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

short CompareDates(stDate Date1, stDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;

	if (IsDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;

	return enDateCompare::After;
}

bool IsDateInPeriod(stDate Date, stPeriod Period)
{
	return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before && CompareDates(Date, Period.EndDate) == enDateCompare::After);
}

int main()
{
	cout << "Enter Period:";
	stPeriod Period = ReadPeriod();

	cout << "\nEnter Date to check:\n";
	stDate Date = ReadFullDate();

	if (IsDateInPeriod(Period, Date))
		cout << "\nYes, Date is within period";
	else
		cout << "\nNo, Date is NOT within period";

	system("pause>0");

	return 0;
}