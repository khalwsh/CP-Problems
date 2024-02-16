#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int work1(string &s1,string &s2)
{
    int res=0;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]!=s2[i])
            res++;
    }
    return res;
}
int main() {
    khaled
    int t;
    cin>>t;
    while(t--) {
       int n;
       cin>>n;
       string s1,s2;
       cin>>s1>>s2;
       string temp=s2;
       reverse(temp.begin(),temp.end());
       long long res1=work1(s1,temp);
       long long res2=work1(s1,s2);
       res1=max(res1,1ll);
       if(res2&1^1)
           res2*=2,res2++;
       else
           res2*=2;
       if(res1&1)
           res1*=2,res1++;
       else
           res1*=2;
       cout<<min(res1,res2)-1<<line;
    }
}
