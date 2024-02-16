#include<bits/stdc++.h>
#define endl '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
//int rec(string s);
//vector<string>v;
int main()
{
    khaled
    string s;
    cin>>s;
    unsigned long long c=0;
    unsigned long long temp=0;
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='b')
            c++;
        else
        {
            temp+=c;
            c+=c;
            c%=1000000007;
        }
    }
  cout<<temp%((long long)pow(10,9)+7);
   // int z=rec(s);
   // cout<<z%((int)pow(10,9)+7);
    //for(auto &Val:v)
      // cout<<Val<<" ";
}
/*int rec(string s)
{
    if((int)s.find("ab")==-1)
        return 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='a'&&s[i+1]=='b')
        {
           s.replace(i,2,"bba");
           //v.emplace_back(s);
           return 1+rec(s);
        }
    }
}*/
