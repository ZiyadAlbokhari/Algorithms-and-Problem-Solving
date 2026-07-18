#include <iostream>

using namespace std;

short ReadDay()
{
	int Day = 0;

	cout << "Please enter a Day? ";
	cin >> Day;

	return Day;
}

short ReadMonth()
{
	int Month = 0;

	cout << "\nPlease enter a Month? ";
	cin >> Month;

	return Month;
}

short ReadYear()
{
	int Year = 0;

	cout << "\nPlease enter a Year? ";
	cin >> Year;

	return Year;
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

struct stDate
{
	short Year = 0;
	short Month = 0;
	short Day = 0;
};

stDate GetDateFromDaysOrderInYear(short DaysOrderInYear, short Year)
{
	stDate Date;
	short RemainingDays = DaysOrderInYear;
	short MonthDays = 0;
	
	Date.Year = Year;
	Date.Month = 1;

	while (true)
	{
		MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}

	return Date;
}

int main()
{
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();
	short DaysOrderInYear = NumberOfDaysFromTheBiginingOfTheYear(Day, Month, Year);

	cout << "\nNumber of Days from the begining of the year is " << DaysOrderInYear << "\n\n";

	stDate Date;
	Date = GetDateFromDaysOrderInYear(DaysOrderInYear, Year);

	cout << "Date for [" << DaysOrderInYear << "] is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");

	return 0;
}