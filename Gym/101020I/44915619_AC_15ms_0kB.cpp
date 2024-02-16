#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
using namespace std;
int dx[]={-1,-1,-1, 0, 0, 1, 1, 1};
int dy[]={-1, 0, 1,-1, 1,-1, 0, 1};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       string x;
       cin>>x;
       map<char,int>mp;
       int sz=x.size();
       for(int i=0;i<sz;i++)
       {
           mp[x[i]]++;
       }
       int odd=0;
       for(auto i:mp)
       {
           if(i.second%2) odd++;
       }
       if(odd<=1)
       {
           string ans="";
           string found="";
           for(auto i:mp)
           {
               int cnt=i.second/2;
               for(int j=0;j<cnt;j++)
                   ans+=i.first;
               if(i.second%2) found=i.first;
           }
           string s=ans;
           reverse(s.begin(),s.end());
           if(!found.empty())
               ans+=found;
           ans+=s;
           cout<<ans<<"\n";
       }
       else cout<<"impossible\n";
    }
    return 0;
}
 