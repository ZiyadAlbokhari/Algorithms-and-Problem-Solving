#include <iostream>

using namespace std;

struct stInfo
{
	short Age;
	bool HasDriverLicense;
	bool HasRecommandtion;
};

stInfo ReadInfo()
{
	stInfo Info;

	cout << "Please enter your age?" << endl;
	cin >> Info.Age;

	cout << "Do you have a driver license?" << endl;
	cin >> Info.HasDriverLicense;

	cout << "Do you have a recommandtion?" << endl;
	cin >> Info.HasRecommandtion;

	return Info;
}

bool isAccepted(stInfo Info)
{
	if (Info.HasRecommandtion)
		return true;
	else
		return (Info.Age > 21 && Info.HasDriverLicense);
}

void PrintResult(stInfo Info)
{
	if (isAccepted(Info))
		cout << "\nHired" << endl;
	else
		cout << "\nRejecred" << endl;
}

int main()
{
	PrintResult(ReadInfo());

	return 0;
}