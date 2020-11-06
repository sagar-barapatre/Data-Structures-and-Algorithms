//() has score 1
//AB has score A+B ,where A and B are balances parenthesis
//(A) has score 2*A ,where A is a balances parenthesis string
//INPUT: "(()(()))"
//OUTPUT:6

#include <bits/stdc++.h>
using namespace std;
    map<int,int> m;

     int findanswer(int l,int r)
    {
        if(l+1==r)return 1;

        int mid=m[l];

        if(mid==r)
        {
            return 2*findanswer(l+1,r-1);
        }

        return findanswer(l,mid) + findanswer(mid+1,r);
    }
int valueOfParanthesis(string str,int n)
{
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')
        {
            s.push(i);
        }
        else
        {
            m[s.top()]=i;
            s.pop();
        }
    }

    return findanswer(0,n-1);
}
int main()
{
    string str;
    cin>>str;
    int n=str.length();
    cout<<valueOfParanthesis(str,n);
}
