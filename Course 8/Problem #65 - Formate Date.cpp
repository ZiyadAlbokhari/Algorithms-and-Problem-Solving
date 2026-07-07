#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stDate
{
	short Year = 0;
	short Month = 0;
	short Day = 0;
};

string ReadStringDate(string Message)
{
	string DateString = "";

	cout << Message;
	getline(cin >> ws, DateString);

	return DateString;
}

vector <string> SplitString(string S1, string Delim)
{
	vector <string> vString;

	string sWord = "";
	int pos = 0;

	while ((pos = S1.find(Delim)) != string::npos)
	{
		sWord = S1.substr(0, pos);

		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		S1.erase(0, pos + Delim.length());
	}

	if (S1 != "")
	{
		vString.push_back(S1);
	}

	return vString;
}

stDate StringToDate(string DateString)
{
	stDate Date;
	vector <string> vDate;

	vDate = SplitString(DateString, "/");

	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoi(vDate[2]);

	return Date;
}

string ReplaceWordInString(string S1, string StringToReplace, string ReplaceTo)
{
	short pos = S1.find(StringToReplace);

	while (pos != string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(), ReplaceTo);
		pos = S1.find(StringToReplace);
	}

	return S1;
}

string FormatDate(stDate Date, string FormateDate = "dd/mm/yyyy")
{
	string FormattedDateString = "";

	FormattedDateString = ReplaceWordInString(FormateDate, "dd", to_string(Date.Day));
	FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
	FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));

	return FormattedDateString;
}

int main()
{
	string DateString = ReadStringDate("Please Enter a Date dd/mm/yyyy? ");

	stDate Date = StringToDate(DateString);

	cout << "\n" << FormatDate(Date) << "\n";
	cout << "\n" << FormatDate(Date, "yyyy/dd/mm") << "\n";
	cout << "\n" << FormatDate(Date, "mm/dd/yyyy") << "\n";
	cout << "\n" << FormatDate(Date, "mm-dd-yyyy") << "\n";
	cout << "\n" << FormatDate(Date, "dd-mm-yyyy") << "\n";
	cout << "\n" << FormatDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";

	system("pause>0");

	return 0;
}