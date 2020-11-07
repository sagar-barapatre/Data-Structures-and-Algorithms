#include <bits/stdc++.h>
using namespace std;

void permutation(string str,int l,int r )
{
    if(l==r)
    {
        cout<<str<<endl;
        return;
    }

    for(int i=l;i<=r;i++)
    {
        swap(str[l],str[i]);

        permutation(str,l+1,r);

        swap(str[l],str[i]);
    }

}
int main()
{
    string str="abc";

    permutation(str,0,str.length()-1);
}
