#include <iostream>

using namespace std;

short ReadNumber()
{
	short Number;

	cout << "Please enter your number?" << endl;
	cin >> Number;

	return Number;
}

void PrintRangeFromNto1_UsingWhile(short N)
{
	short Counter = N + 1;

	cout << "Range printed using While Statement: ";

	while (Counter > 1)
	{
		Counter--;
		cout << Counter << " ";
	}

	cout << endl;
}

void PrintRangeFromNto1_UsingDoWhile(short N)
{
	short Counter = N + 1;

	cout << "Range printed using Do..While Statement: ";

	do
	{
		Counter--;
		cout << Counter << " ";

	} while (Counter > 1);

	cout << endl;
}

void PrintRangeFromNto1_UsingFor(short N)
{
	cout << "Range printed using For Statement: ";

	for (short Counter = N; Counter >= 1; Counter--)
		cout << Counter << " ";

	cout << endl;
}

int main()
{
	short N = ReadNumber();

	PrintRangeFromNto1_UsingWhile(N);
	PrintRangeFromNto1_UsingDoWhile(N);
	PrintRangeFromNto1_UsingFor(N);

	return 0;
}