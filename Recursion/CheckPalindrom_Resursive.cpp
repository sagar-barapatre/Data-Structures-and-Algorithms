#include <bits/stdc++.h>
using namespace std;

bool isPalindrom(string str,int i,int n)
{
    if(i>=n/2)return true;

    if(str[i]==str[n-1-i])
    {
        return isPalindrom(str,i+1,n);
    }

    return false;
}
int main()
{
    string str="tehaet";
    int n=str.length();
    cout<<isPalindrom(str,0,n);
}
