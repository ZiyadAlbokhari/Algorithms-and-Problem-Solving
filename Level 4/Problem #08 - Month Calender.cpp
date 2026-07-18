#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

short ReadYear()
{
	int Year = 0;

	cout << "Please enter a Year? ";
	cin >> Year;

	return Year;
}

short ReadMonth()
{
	int Month = 0;

	cout << "\nPlease enter a Month? ";
	cin >> Month;

	return Month;
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

string MonthShortName(short MonthNumber)
{
	string arrMonthNames[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	return arrMonthNames[MonthNumber - 1];
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m, d;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	return arrDayNames[DayOfWeekOrder];
}

void PrintMonthCalender(short Month, short Year)
{
	short NumberOfDay = NumberOfDaysInAMonth(Month, Year);
	short Current = DayOfWeekOrder(1, Month, Year);

	printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	short i;

	for (i = 0; i < Current; i++)
		printf("     ");

	for (short j = 1; j <= NumberOfDay; j++)
	{
		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}

	printf("\n  _________________________________\n");
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	
	PrintMonthCalender(Month, Year);

	system("pause>0");

	return 0;
}