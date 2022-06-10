#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct Student
{
	int number;
	int matchScore;
	int informationScore;
};

bool Compare(Student a, Student b);

int main()
{
	int n;
	cin >> n;

	vector<Student> st(n);
	for (int i = 0; i < n; i++)
	{
		st[i].number = i + 1;
		cin >> st[i].matchScore >> st[i].informationScore;
	}

	sort(st.begin(), st.end(), Compare);

	for (int i = 0; i < n; i++)
		cout << st[i].number << ' ' << st[i].matchScore << ' ' << st[i].informationScore << endl;

	return 0;
}

bool Compare(Student a, Student b)
{
	if (a.matchScore > b.matchScore)
		return 1;
	else if (a.matchScore < b.matchScore)
		return 0;
	else
	{
		if (a.informationScore > b.informationScore)
			return 1;
		else if (a.informationScore < b.informationScore)
			return 0;
		else
			return a.number < b.number;
	}
}