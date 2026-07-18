#include <iostream>

using namespace std;

void ReadNumbers(short& Num1, short& Num2)
{
	cout << "Please enter Number A?" << endl;
	cin >> Num1;

	cout << "Please enter Number B?" << endl;
	cin >> Num2;
}

void SwapOfNumbers(short& A, short& B)
{
	short Temp;

	Temp = A;
	A = B;
	B = Temp;
}

void PrintResults(short Num1, short Num2)
{
	cout << "\nNumber1 = " <<  Num1 << endl;
	cout << "Number2 = " << Num2 << endl;
}

int main()
{
	short Num1, Num2;
	ReadNumbers(Num1, Num2);
	PrintResults(Num1, Num2);
	SwapOfNumbers(Num1, Num2);
	PrintResults(Num1, Num2);

	return 0;
}