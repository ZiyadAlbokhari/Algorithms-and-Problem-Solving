#include <iostream>

using namespace std;

enum enPassFail { Pass = 1, Fail = 2 };

short ReadMark()
{
	short Mark = 0;

	cout << "Please enter your mark?" << endl;
	cin >> Mark;

	return Mark;
}

enPassFail CheckMark(short Mark)
{
	if (Mark >= 50)
		return enPassFail::Pass;
	else
		return enPassFail::Fail;
}

void PrintResults(short Mark)
{
	if (CheckMark(Mark) == enPassFail::Pass)
		cout << "\nYou Passed" << endl;
	else
		cout << "\nYou Failed" << endl;
}

int main()
{
	PrintResults(ReadMark());

	return 0;
}