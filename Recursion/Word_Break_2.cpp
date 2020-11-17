#include <bits/stdc++.h>
using namespace std;
void findAnswer(int i,string a,unordered_map<string,int> mp,string temp,vector<string> &ans)
{
    if(i==a.size())
    {
        ans.push_back(temp);

        return ;
    }

    string curr="";

    for(int j=i;j<a.size();j++)
    {
        curr+=a[j];

        if(mp.find(curr)!=mp.end())
        {
            if(j<a.size()-1)
                findAnswer(j+1,a,mp,temp+curr+" ",ans);

            else
                findAnswer(j+1,a,mp,temp+curr,ans);
        }
    }


}
void wordBreak(string a, vector<string> &b)
{
    unordered_map<string,int> mp;

    for(int i=0;i<b.size();i++)
    {
        mp[b[i]]=1;
    }

    vector<string> ans;

    findAnswer(0,a,mp,"",ans);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}



int main() {

   string a="catsanddog";
   vector<string> b={"cat", "cats", "sand", "and", "dog"};

   wordBreak(a,b);
}
