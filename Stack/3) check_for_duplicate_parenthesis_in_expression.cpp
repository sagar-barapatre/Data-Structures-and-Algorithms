#include<iostream>
#include<stack>
using namespace std;

bool duplicate(string str)
{
	stack<char> s;
	for (char c : str)
	{
		if (c != ')')
			s.push(c);

		else
		{
			if (s.top() == '(')
				return true;

			while (s.top() != '(')
				s.pop();

			s.pop();
		}
	}
	return false;
}

int main()
{
	string str = "(x+y)";
	if (duplicate(str))
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}