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

short ReadDaysToAdd()
{
	int Days = 0;

	cout << "\nHow many days to add? ";
	cin >> Days;

	return Days;
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

stDate ReadFullDate()
{
	stDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

stDate DateAddDays(short Days, stDate Date)
{
	short RemainingDays = Days + NumberOfDaysFromTheBiginingOfTheYear(Date.Day, Date.Month, Date.Year);
	short MonthDays = 0;

	Date.Month = 1;

	while (true)
	{
		MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;

			if (Date.Month > 12)
			{
				Date.Month = 1;
				Date.Year++;
			}
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
	stDate Date = ReadFullDate();
	short Days = ReadDaysToAdd();

	Date = DateAddDays(Days, Date);

	cout << "\nDate after adding [" << Days << "] days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");

	return 0;
}