#include<iostream>
#include<stack>
using namespace std;

string decodeMinimum(string str)
{
	string result = "";
	stack<int> s;
	for (int i = 0 ; i <= str.length() ; i++)
	{
		s.push(i + 1);

		if (i == str.length() || str[i] == 'I')
		{
			while (!s.empty())
			{
				result += to_string(s.top());
				s.pop();
			}
		}

	}
	return result;
}

int main()
{
	string str = "IDIDII";
	cout << decodeMinimum(str);
	return 0;
}