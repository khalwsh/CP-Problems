#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool valid(int i,int j,int n,int m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const int&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const int&mod){return (((x%mod)+(y%mod))+mod)%mod;}
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
#define int long long
/*--------------------------------------------------------------------------------------------------------------------*/
int n;
int w;
vector<pair<int,int>>values;
vector<vector<int>>dp;
long long solve(int index=n-1,int W=w)
{
    if(index==0)
    {
        if(W>=values[0].first)return values[0].second;
        return 0;
    }
    if(dp[index][W]!=-1)return dp[index][W];
    int take=0;
    if(W-values[index].first>=0)
     take=solve(index-1,W-values[index].first)+values[index].second;
    int leave=solve(index-1,W);
    return dp[index][W]=max(leave,take);
}
signed main() {
    khaled
    cin>>n>>w;
    dp.resize(n,vector<int>(w+1,-1));
    values.resize(n);
    for(auto &val:values)cin>>val.first>>val.second;
    cout<<solve();
}
