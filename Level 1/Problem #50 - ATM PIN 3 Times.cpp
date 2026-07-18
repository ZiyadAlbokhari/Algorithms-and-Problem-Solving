#include <iostream>

using namespace std;

string ReadPinCode()
{
	string PinCode;

	cout << "Please enter PIN code\n";
	cin >> PinCode;

	return PinCode;
}

bool Login()
{
	string PinCode;
	int Counter = 3;

	do
	{
		Counter--;

		PinCode = ReadPinCode();

		if (PinCode == "1234")
		{
			return 1;
		}
		else
		{
			cout << "\nWrong PIN, you have " << Counter << " more tries \n";
			system("color 4F");
		}

	} while (Counter >= 1 && PinCode != "1234");

	return 0;
}

int main()
{
	if (Login())
	{
		system("color 2F");
		cout << "\nYour account balance is " << 7500 << '\n';
	}
	else
	{
		cout << "\nYour cars blocked call the bank to help. \n";
	}

	return 0;
}