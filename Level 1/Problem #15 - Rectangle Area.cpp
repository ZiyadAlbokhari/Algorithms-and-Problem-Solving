#include <iostream>

using namespace std;

void ReadNumbers(float& A, float& B)
{
	cout << "Please enter rectangle width A?" << endl;
	cin >> A;

	cout << "Please enter rectangle length B?" << endl;
	cin >> B;
}

float CalculatenRectangleArea(float A, float B)
{
	return A * B;
}

void PrintResult(float Area)
{
	cout << "\nRectangle Area = " << Area << endl;
}

int main()
{
	float A, B;
	ReadNumbers(A, B);
	PrintResult(CalculatenRectangleArea(A, B));

	return 0;
}