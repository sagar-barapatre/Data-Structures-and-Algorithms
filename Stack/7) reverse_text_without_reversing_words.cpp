#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;

string reverseText(string str)
{
	stack<string> s;
	int high = 0;
	int low = 0;

	for (int i = 0 ; i < str.length() ; i++)
	{
		if (str[i] == ' ')
		{
			s.push(str.substr(low, high - low + 1));
			high = low = i + 1;
		}
		else
			high = i;
	}
	s.push(str.substr(low));
	str.clear();

	while (!s.empty())
	{
		str.append(s.top());
		str.append(" ");
		s.pop();
	}
	str.erase(prev(str.end()));
	return str;
}

int main()
{
	string str = "Barapatre Sagar is name My";

	cout << reverseText(str) << endl;
//Output : My name is Sagar Barapatre
	return 0;
}