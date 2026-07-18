#include <iostream>

using namespace std;

short ReadNumber()
{
	short Number;

	cout << "Please enter a number?" << endl;
	cin >> Number;

	return Number;
}

short ReadPower()
{
	short Number;

	cout << "Please enter the power?" << endl;
	cin >> Number;

	return Number;
}

short NumberOfM(short Number, short M)
{
	if (M == 0)
		return 1;

	short P = 1;

	for (short i = 1; i <= M; i++)
		P *= Number;

	return P;
}

int main()
{
	short N, P;

	N = ReadNumber();
	P = ReadPower();

	cout << endl << "Result = " << NumberOfM(N, P) << endl;

	return 0;
}