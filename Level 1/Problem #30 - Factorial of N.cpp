#include <iostream>

using namespace std;

short ReadPositiveNumber(string Message)
{
	short Number;

	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number < 0);

	return Number;
}

short Factorial(short N)
{
	short F = 1;

	for (short Counter = N; Counter >= 1; Counter--)
		F *= Counter;

	return F;
}

int main()
{
	cout << Factorial(ReadPositiveNumber("Please enter a positive number?")) << endl;

	return 0;
}