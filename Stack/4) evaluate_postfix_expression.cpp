#include<iostream>
#include<stack>
using namespace std;

int postfixExpression(string str)
{
	stack<char> s;

	for (int i = 0 ; i < str.length() ; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			s.push(str[i] - '0');
		else
		{
			int x = s.top();
			s.pop();

			int y = s.top();
			s.pop();

			if (str[i] == '+')
				s.push(y + x);

			else if (str[i] == '-')
				s.push(y - x);

			else if (str[i] == '*')
				s.push(y * x);

			else if (str[i] == '/')
				s.push(y / x);
		}
	}
	return s.top();
}

int main()
{
	string str = "231*+9-";
	cout << postfixExpression(str) << endl;
	return 0;
}