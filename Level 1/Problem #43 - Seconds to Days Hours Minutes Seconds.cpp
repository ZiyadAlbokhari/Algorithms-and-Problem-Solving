#include <iostream>

using namespace std;

struct stTaskDuration
{
	int NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds;
};

int ReadPositiveNumber(string Message)
{
	int Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

stTaskDuration SecondsToTaskDuration(int TotalSeconds)
{
	stTaskDuration TaskDuration;

	const int SecondsPerDays = 24 * 60 * 60;
	const int SecondsPerHours = 60 * 60;
	const int SecondsPerMinutes = 60;

	int Remainder = 0;

	TaskDuration.NumberOfDays = floor(TotalSeconds / SecondsPerDays);
	Remainder = TotalSeconds % SecondsPerDays;
	TaskDuration.NumberOfHours = floor(Remainder / SecondsPerHours);
	Remainder = Remainder % SecondsPerHours;
	TaskDuration.NumberOfMinutes = floor(Remainder / SecondsPerMinutes);
	Remainder = Remainder % SecondsPerMinutes;
	TaskDuration.NumberOfSeconds = Remainder;

	return TaskDuration;
}

void PrintTaskDurationDetalis(stTaskDuration TaskDuration)
{
	cout << "\n";
	cout << TaskDuration.NumberOfDays << ":" << TaskDuration.NumberOfHours << ":" << TaskDuration.NumberOfMinutes << ":" << TaskDuration.NumberOfSeconds << "\n";
}

int main()
{
	int TotalSeconds = ReadPositiveNumber("Please Enter Total Seconds?");
	PrintTaskDurationDetalis(SecondsToTaskDuration(TotalSeconds));

	return 0;
}