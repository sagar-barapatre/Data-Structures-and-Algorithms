#include<bits/stdc++.h>
using namespace std;

int str_toInteger(string str,int i)
{
    if(i==0)
    {
        return  (str[0]-'0');
    }
    int temp= str_toInteger(str,i-1);

   temp=temp*10+ str[i]-'0';
   return temp;

}
int main()
{
    string str="451261268";
    int n=str.length();

    cout<<str_toInteger(str,n-1);

}
