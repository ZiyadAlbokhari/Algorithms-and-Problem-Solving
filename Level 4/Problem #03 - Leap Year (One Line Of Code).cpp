#include <iostream>

using namespace std;

short ReadYear()
{
	int Year = 0;

	cout << "Enter a year to check? ";
	cin >> Year;

	return Year;
}

bool IsLeapYear(short Year)
{
	return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

int main()
{
	short Year = ReadYear();

	if (IsLeapYear(Year))
		cout << "\nYes, Year [" << Year << "] is a leap year.\n";
	else
		cout << "\nNo, Year [" << Year << "] is NOT a leap year.\n";

	system("pause>0");

	return 0;
}