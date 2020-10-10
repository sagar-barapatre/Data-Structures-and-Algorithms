#include<iostream>
#include<stack>
using namespace std;

string reversestring(string str)
{
	string ans = "";
	stack<char> s;

	for (int i = 0 ; i < str.length() ; i++)
		s.push(str[i]);

	int k = 0;
	while (!s.empty())
	{
		str[k++] = s.top();
		s.pop();
	}
	return str;
}

int main()
{
	string s = "sagar";
	cout << reversestring(s) << endl;
	return 0;
}