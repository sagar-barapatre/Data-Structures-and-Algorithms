#include<iostream>
#include<stack>
using namespace std;

bool expression(string str)
{
	stack<char> s;
	char x;
	for (int i = 0 ; i < str.length() ; i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			s.push(str[i]);
			continue;
		}

		if (s.empty())
			return false;
		switch (str[i])
		{
		case ')':
			x = s.top();
			s.pop();
			if (x == '{' || x == '[')
				return false;
			break;

		case '}':

			// Store the top element in b
			x = s.top();
			s.pop();
			if (x == '(' || x == '[')
				return false;
			break;

		case ']':

			// Store the top element in c
			x = s.top();
			s.pop();
			if (x == '(' || x == '{')
				return false;
			break;
		}
	}
	return (s.empty());
}

int main()
{
	string str = "{{{{{][][][()({}[]";
	if (expression(str))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}