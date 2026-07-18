#include <iostream>
#include <string>

using namespace std;

short ReadNumber()
{
	short Num;

	cout << "Please enter a number?" << endl;
	cin >> Num;

	return Num;
}

float CalculateHalfOfNumber(short Num)
{
	return (float)Num / 2;
}

void PrintResult(short Num)
{
	string Result = "Half of " + to_string(Num) + " is " + to_string(CalculateHalfOfNumber(Num));

	cout << Result << endl;
}

int main()
{
	PrintResult(ReadNumber());

	return 0;
}