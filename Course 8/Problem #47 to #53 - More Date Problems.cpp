#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>

using namespace std;

struct stDate
{
	short Year = 0;
	short Month = 0;
	short Day = 0;
};

stDate GetSystemDate()
{
	stDate Date;

	time_t t = time(0);
	tm* now = localtime(&t);

	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;

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

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m, d;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stDate Date)
{
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	return arrDayNames[DayOfWeekOrder];
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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

bool IsEndOfWeek(stDate Date)
{
	return (DayOfWeekOrder(Date) == 6);
}

bool IsWeekEnd(stDate Date)
{
	short DayIndex = DayOfWeekOrder(Date);

	return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(stDate Date)
{
	return !IsWeekEnd(Date);
}

short DaysUnitTheEndOfWeek(stDate Date)
{
	return 6 - DayOfWeekOrder(Date);
}

short DaysUnitTheEndOfMonth(stDate Date)
{
	stDate EndOfMonthDate;

	EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
	EndOfMonthDate.Month = Date.Month;
	EndOfMonthDate.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOfMonthDate, true);
}

short DaysUnitTheEndOfYear(stDate Date)
{
	stDate EndOYearDate;

	EndOYearDate.Day = 31;
	EndOYearDate.Month = 12;
	EndOYearDate.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOYearDate, true);
}

int main()
{
	stDate Date = GetSystemDate();

	cout << "Today is " << DayShortName(DayOfWeekOrder(Date)) << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	//---------------------

	cout << "\nIs it End of Week?\n";
	if (IsEndOfWeek(Date))
		cout << "Yes it's Saturday, it's of week.";
	else
		cout << "No it's Not end of week.";

	//---------------------

	cout << "\n\nIs it WeekEnd?\n";
	if (IsWeekEnd(Date))
		cout << "Yes it is a week end.";
	else
		cout << "No today is " << DayShortName(DayOfWeekOrder(Date)) << ", Not a weekend.";

	//---------------------

	cout << "\n\nIs it Business Day?\n";
	if (IsBusinessDay(Date))
		cout << "Yes it is a business day.";
	else
		cout << "No it is NOT a business day.";

	//---------------------

	cout << "\n\nDays unitl end of week  : " << DaysUnitTheEndOfWeek(Date) << " Day(s).";
	cout << "\nDays unitl end of month : " << DaysUnitTheEndOfMonth(Date) << " Day(s).";
	cout << "\nDays unitl end of year  : " << DaysUnitTheEndOfYear(Date) << " Day(s).";

	system("pause>0");

	return 0;
}