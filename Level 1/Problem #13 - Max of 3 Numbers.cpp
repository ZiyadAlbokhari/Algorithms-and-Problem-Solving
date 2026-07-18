#include <iostream>

using namespace std;

void ReadNumbers(short& A, short& B, short& C)
{
	cout << "Please enter Number A?" << endl;
	cin >> A;

	cout << "Please enter Number B?" << endl;
	cin >> B;

	cout << "Please enter Number C?" << endl;
	cin >> C;
}

short MaxOf3Number(short A, short B, short C)
{
	if (A > B)
		if (A > C)
			return A;
		else
			return C;

	else
		if (B > C)
			return B;
		else
			return C;
}

void PrintResults(short Max)
{
	cout << "\nThe Maximum Number is: " << Max << endl;
}

int main()
{
	short A, B, C;
	ReadNumbers(A, B, C);
	PrintResults(MaxOf3Number(A, B, C));

	return 0;
}