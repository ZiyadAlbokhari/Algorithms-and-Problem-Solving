#include <iostream>

using namespace std;

enum enNumberType { Even = 1, Odd = 2};

short ReadNumber()
{
	short Num;

	cout << "Please enter a number?" << endl;
	cin >> Num;

	return Num;
}

enNumberType CheckNumberType(short Num)
{
	short Result = Num % 2;

	if (Result == 0)
		return enNumberType::Even;
	else
		return enNumberType::Odd;
}

void PrintNumberType(enNumberType NumberType)
{
	if (NumberType == enNumberType::Even)
		cout << "\nNumber is Even." << endl;
	else
		cout << "\nNumber is Odd." << endl;
}

int main()
{
	PrintNumberType(CheckNumberType(ReadNumber()));

	return 0;
}