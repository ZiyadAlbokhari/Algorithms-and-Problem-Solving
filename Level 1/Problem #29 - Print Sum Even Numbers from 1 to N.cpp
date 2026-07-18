#include <iostream>

using namespace std;

enum enOddOrEven { Odd = 1, Even = 2 };

short ReadNumber()
{
	short N;

	cout << "Please enter a number?" << endl;
	cin >> N;

	return N;
}

enOddOrEven CheckOddOrEven(short Number)
{
	if (Number % 2 != 0)
		return enOddOrEven::Odd;
	else
		return enOddOrEven::Even;
}

short SumEvenNumbersFrom1toN_UsingWhile(short N)
{
	short Counter = 0;
	short Sum = 0;

	cout << "\nSum even numbers using While Statement: " << endl;

	while (Counter < N)
	{
		Counter++;

		if (CheckOddOrEven(Counter) == enOddOrEven::Even)
			Sum += Counter;
	}

	return Sum;
}

short SumEvenNumbersFrom1toN_UsingDoWhile(short N)
{
	short Counter = 0;
	short Sum = 0;

	cout << "Sum even numbers using Do..While Statement: " << endl;

	do
	{
		Counter++;

		if (CheckOddOrEven(Counter) == enOddOrEven::Even)
			Sum += Counter;
	} while (Counter < N);

	return Sum;
}

short SumEvenNumbersFrom1toN_UsingFor(short N)
{
	short Sum = 0;

	cout << "Sum even numbers using For Statement: " << endl;

	for (short Counter = 1; Counter <= N; Counter++)
	{
		if (CheckOddOrEven(Counter) == enOddOrEven::Even)
			Sum += Counter;
	}

	return Sum;
}

int main()
{
	short N = ReadNumber();
	cout << SumEvenNumbersFrom1toN_UsingWhile(N) << endl;
	cout << SumEvenNumbersFrom1toN_UsingDoWhile(N) << endl;
	cout << SumEvenNumbersFrom1toN_UsingFor(N) << endl;

	return 0;
}