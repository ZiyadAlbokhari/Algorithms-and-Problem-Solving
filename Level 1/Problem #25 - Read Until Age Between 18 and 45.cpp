#include <iostream>

using namespace std;

short ReadAge()
{
	short Age;

	cout << "Please enter your age?" << endl;
	cin >> Age;

	return Age;
}

bool ValidateNumberInRange(short Number, short From, short To)
{
	return (Number >= From && Number <= To);
}

short ReadUntilAgeBetween(short From, short To)
{
	short Age;

	do
	{
		Age = ReadAge();

	} while (!ValidateNumberInRange(Age, From, To));

	return Age;
}

void PrintResult(short Age)
{
	cout << "\nYour age is " << Age << endl;
}

int main()
{
	PrintResult(ReadUntilAgeBetween(18, 45));

	return 0;
}