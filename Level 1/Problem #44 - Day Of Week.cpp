#include <iostream>

using namespace std;

enum enDayOfWeek { Sun = 1, Mon = 2, Tue = 3, Wed = 4, Thu = 5, Fri = 6, Sat = 7 };

int ReadNumberInRange(string Message, int From, int To)
{
	int Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number < From || Number > To);

	return Number;
}

enDayOfWeek ReadDayOfWeek()
{
	return (enDayOfWeek)ReadNumberInRange("Please Enter Number Of Day Sun=1,Mon=2,Tue=3,Wed=4,Thu=5,Fri=6,Sat=7", 1, 7);
}

string GetDayOfWeek(enDayOfWeek Day)
{
	switch (Day)
	{
	case enDayOfWeek::Sun:
		return "Its Sunday";
	case enDayOfWeek::Mon:
		return "Its Monday";
	case enDayOfWeek::Tue:
		return "Its Tuesday";
	case enDayOfWeek::Wed:
		return "Its Wednesday";
	case enDayOfWeek::Thu:
		return "Its Thursday";
	case enDayOfWeek::Fri:
		return "Its Friday";
	case enDayOfWeek::Sat:
		return "Its Saturday";
	default:
		return "Wrong Day";
	}
}

int main()
{
	cout << GetDayOfWeek(ReadDayOfWeek()) << endl;

	return 0;
}