#include <iostream>

using namespace std;

enum enPassFail { Pass = 1, Fail = 2 };

void ReadNumbers(short& Mark1, short& Mark2, short& Mark3)
{
	cout << "Please enter your mark 1?" << endl;
	cin >> Mark1;

	cout << "Please enter your mark 2?" << endl;
	cin >> Mark2;

	cout << "Please enter your mark 3?" << endl;
	cin >> Mark3;
}

short SumOf3Numbers(short Mark1, short Mark2, short Mark3)
{
	return Mark1 + Mark2 + Mark3;
}

float CalculateAvarage(short Mark1, short Mark2, short Mark3)
{
	return (float)SumOf3Numbers(Mark1, Mark2, Mark3) / 3;
}

enPassFail CheckAverage(float Average)
{
	if (Average >= 50)
		return enPassFail::Pass;
	else
		return enPassFail::Fail;
}

void PrintResults(float Average)
{
	cout << "\nYour average is: " << Average << endl;

	if (CheckAverage(Average) == enPassFail::Pass)
		cout << "is Passed" << endl;
	else
		cout << "is Faild" << endl;
}

int main()
{
	short Mark1, Mark2, Mark3;
	ReadNumbers(Mark1, Mark2, Mark3);
	PrintResults(CalculateAvarage(Mark1, Mark2, Mark3));

	return 0;
}