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

void PrintResult(short Age)
{
	if (ValidateNumberInRange(Age, 18, 45))
		cout << Age << " is a valid age" << endl;
	else
		cout << Age << " is invalid age" << endl;
}

int main()
{
	PrintResult(ReadAge());

	return 0;
}