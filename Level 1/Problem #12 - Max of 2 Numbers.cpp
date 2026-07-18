#include <iostream>

using namespace std;

void ReadNumbers(short& Num1, short& Num2)
{
	cout << "Please enter Number 1?" << endl;
	cin >> Num1;

	cout << "Please enter Number 2?" << endl;
	cin >> Num2;
}

short MaxOf2Number(short Num1, short Num2)
{
	if (Num1 > Num2)
		return Num1;
	else
		return Num2;
}

void PrintResults(short Max)
{
	cout << "\nThe Maximum Number is: " << Max << endl;
}

int main()
{
	short Num1, Num2;
	ReadNumbers(Num1, Num2);
	PrintResults(MaxOf2Number(Num1, Num2));

	return 0;
}