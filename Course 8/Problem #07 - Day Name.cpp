#include <iostream>

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

short ReadDay()
{
	int Day = 0;

	cout << "\nPlease enter a Day? ";
	cin >> Day;

	return Day;
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

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();

	cout << "\nDate      : " << Day << "/" << Month << "/" << Year;
	cout << "\nDay Order : " << DayOfWeekOrder(Day, Month, Year);
	cout << "\nDay Name  : " << DayShortName(DayOfWeekOrder(Day, Month, Year));

	system("pause>0");

	return 0;
}