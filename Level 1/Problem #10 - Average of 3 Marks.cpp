#include <iostream>

using namespace std;

void ReadNumbers(short& Mark1, short& Mark2, short& Mark3)
{
	cout << "Please enter your mark 1?" << endl;
	cin >> Mark1;

	cout << "Please enter your mark 2?" << endl;
	cin >> Mark2;

	cout << "Please enter your mark 3?" << endl;
	cin >> Mark3;
}

short SumOf3Marks(short Mark1, short Mark2, short Mark3)
{
	return Mark1 + Mark2 + Mark3;
}

float CalculateOfAverage(short Mark1, short Mark2, short Mark3)
{
	return (float)SumOf3Marks(Mark1, Mark2, Mark3) / 3;
}

void PrintResults(float Average)
{
	cout << "\nThe average is: " << Average << endl;
}

int main()
{
	short Mark1, Mark2, Mark3;
	ReadNumbers(Mark1, Mark2, Mark3);
	PrintResults(CalculateOfAverage(Mark1, Mark2, Mark3));

	return 0;
}