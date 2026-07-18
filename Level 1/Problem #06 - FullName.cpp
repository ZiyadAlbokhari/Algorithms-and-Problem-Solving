#include <iostream>

using namespace std;

struct stInfo
{
	string FirstName;
	string LastName;
};

stInfo ReadFullname()
{
	stInfo Info;

	cout << "Please enter your first name?" << endl;
	cin >> Info.FirstName;

	cout << "Please enter your last name?" << endl;
	cin >> Info.LastName;

	return Info;
}

string GetFullName(stInfo Info, bool Reversed)
{
	string FullName = "";

	if (Reversed)
		FullName = Info.LastName + " " + Info.FirstName;
	else
		FullName = Info.FirstName + " " + Info.LastName;

	return FullName;
}

void PrintFullName(string FullName)
{
	cout << "\nYour full name is: " << FullName << endl;
}

int main()
{
	PrintFullName(GetFullName(ReadFullname(), false));

	return 0;
}