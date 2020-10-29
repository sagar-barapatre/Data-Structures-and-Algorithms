#include<bits/stdc++.h>
using namespace std;
int expo(int a,int b)
{
    if(b==0)return 1;

    int smallans=expo(a,b/2);
    smallans*=smallans;

    if(b%2==1)
    {
        smallans*=a;
    }

    return smallans;
}
int main()
{
    int a,b;
    cin>>a>>b;

    cout<<expo(a,b);
}
