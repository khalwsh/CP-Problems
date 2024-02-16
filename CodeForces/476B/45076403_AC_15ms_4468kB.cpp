#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<vector<vector<int>>>dp;
int number_of_way(int plus1,int plus2,int minus1,int minus2,int mark)
{
    if(mark==0)
        return plus1==plus2&&minus1==minus2;
    if(dp[plus2][minus2][mark]!=-1)return dp[plus2][minus2][mark];
    return dp[plus2][minus2][mark]=number_of_way(plus1,plus2+1,minus1,minus2,mark-1)+ number_of_way(plus1,plus2,minus1,minus2+1,mark-1);
}
signed main() {
    khaled
    string s1;
    string s2;
    cin>>s1>>s2;
    dp.resize(100);
    for(auto &val:dp)val.resize(100,vector<int>(100,-1));
    int plus1=count(s1.begin(),s1.end(),'+');
    int minus1=count(s1.begin(),s1.end(),'-');
    int plus2= count(s2.begin(),s2.end(),'+');
    int minus2=count(s2.begin(),s2.end(),'-');
    int mark=count(s2.begin(),s2.end(),'?');
    cout<<fixed<<showpoint<<setprecision(12)<<number_of_way(plus1,plus2,minus1,minus2,mark)*(1.0)/(1<<mark);
}