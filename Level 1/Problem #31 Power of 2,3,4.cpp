#include <iostream>

using namespace std;

short ReadNumber()
{
	short Number;

	cout << "Please enter a number?" << endl;
	cin >> Number;

	return Number;
}

void PowerOf2_3_4(short Number)
{
	short a, b, c;

	a = Number * Number;
	b = Number * Number * Number;
	c = Number * Number * Number * Number;

	cout << a << " " << b << " " << c << endl;
}

int main()
{
	PowerOf2_3_4(ReadNumber());

	return 0;
}