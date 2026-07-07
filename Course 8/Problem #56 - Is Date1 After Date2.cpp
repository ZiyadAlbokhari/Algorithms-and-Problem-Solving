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

bool IsLeapYear(short Year)
{
	return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	short NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

short NumberOfDaysFromTheBiginingOfTheYear(short Day, short Month, short Year)
{
	short TotalDays = 0;

	for (short i = 1; i <= Month - 1; i++)
	{
		TotalDays += NumberOfDaysInAMonth(i, Year);
	}

	TotalDays += Day;

	return TotalDays;
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

int main()
{
	cout << "Enter Date1:";
	stDate Date1 = ReadFullDate();

	cout << "\nEnter Date2:";
	stDate Date2 = ReadFullDate();

	if (IsDate1AfterDate2(Date1, Date2))
		cout << "\nYes, Date1 is After Date2.";
	else
		cout << "\nNo, Date1 is NOT After Date2.";

	system("pause>0");

	return 0;
}