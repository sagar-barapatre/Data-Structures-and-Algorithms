#include <bits/stdc++.h>
using namespace std;

void subsequence(string inp,string out,int i)
{
    if(i==inp.length())
    {
        //print output
        if(out=="")
        {
            cout<<"EmptyString"<<" ";
        }
        cout<<out<<" ";
        return ;
    }

    subsequence(inp,out,i+1);

    out=out+inp[i];
    subsequence(inp,out,i+1);

}
int main()
{
    string inp="abc",out="";

    subsequence(inp,out,0);

}
