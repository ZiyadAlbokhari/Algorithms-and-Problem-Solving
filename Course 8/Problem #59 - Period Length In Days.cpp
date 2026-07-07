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

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}

	return Date;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludEndDay = false)
{
	int Days = 0;

	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}

	return IncludEndDay ? ++Days : Days;
}

int PeriodLengthInDays(stPeriod Period, bool IncludEndDate = false)
{
	return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludEndDate);
}

int main()
{
	cout << "Enter Period:";
	stPeriod Period = ReadPeriod();

	cout << "\nPeriod Length is: " << PeriodLengthInDays(Period);
	cout << "\nPeriod Length (Including End Date) is: " << PeriodLengthInDays(Period, true);

	system("pause>0");

	return 0;
}