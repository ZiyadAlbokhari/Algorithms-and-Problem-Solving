#include <iostream>

using namespace std;

float ReadPositiveNumber(string Message)
{
	float Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

float TotalMonths(float LoanAmount, float MonthlyInstalment)
{
	return (float)LoanAmount / MonthlyInstalment;
}

int main()
{
	float LoanAmount = ReadPositiveNumber("Please Enter Loan Amount?");
	float MonthlyInstalment = ReadPositiveNumber("Please Enter Monthly Instalment?");

	cout << "\nTotal Months to pay = " << TotalMonths(LoanAmount, MonthlyInstalment) << endl;

	return 0;
}