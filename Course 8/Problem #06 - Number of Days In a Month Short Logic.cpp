#include <iostream>

using namespace std;

short ReadYear()
{
	int Year = 0;

	cout << "Enter a year to check? ";
	cin >> Year;

	return Year;
}

short ReadMonth()
{
	int Month = 0;

	cout << "\nEnter a month to check? ";
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

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\nNumber of Days in Month [" << Month << "] is " << NumberOfDaysInAMonth(Month, Year);

	system("pause>0");

	return 0;
}