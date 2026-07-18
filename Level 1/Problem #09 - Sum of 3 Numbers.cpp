#include <iostream>

using namespace std;

void ReadNumbers(short& Num1, short& Num2, short& Num3)
{
	cout << "Please enter your number 1?" << endl;
	cin >> Num1;

	cout << "Please enter your number 2?" << endl;
	cin >> Num2;

	cout << "Please enter your number 3?" << endl;
	cin >> Num3;
}

short SumOf3Numbers(short Num1, short Num2, short Num3)
{
	return Num1 + Num2 + Num3;
}

void PrintResults(short Total)
{
	cout << "\nThe total sum of numbers is: " << Total << endl;
}

int main()
{
	short Num1, Num2, Num3;
	ReadNumbers(Num1, Num2, Num3);
	PrintResults(SumOf3Numbers(Num1, Num2, Num3));

	return 0;
}