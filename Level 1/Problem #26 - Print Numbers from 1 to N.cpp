#include <iostream>

using namespace std;

short ReadNumber()
{
	short Number;

	cout << "Please enter your number?" << endl;
	cin >> Number;

	return Number;
}

void PrintRangeFrom1toN_UsingWhile(short N)
{
	short Counter = 0;

	cout << "Range printed using While Statement: ";

	while (Counter < N)
	{
		Counter++;
		cout << Counter << " ";
	}

	cout << endl;
}

void PrintRangeFrom1toN_UsingDoWhile(short N)
{
	short Counter = 0;

	cout << "Range printed using Do..While Statement: ";

	do
	{
		Counter++;
		cout << Counter << " ";

	} while (Counter < N);

	cout << endl;
}

void PrintRangeFrom1toN_UsingFor(short N)
{
	cout << "Range printed using For Statement: ";

	for (short Counter = 1; Counter <= N; Counter++)
		cout << Counter << " ";

	cout << endl;
}

int main()
{
	short N = ReadNumber();

	PrintRangeFrom1toN_UsingWhile(N);
	PrintRangeFrom1toN_UsingDoWhile(N);
	PrintRangeFrom1toN_UsingFor(N);

	return 0;
}