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
vector<int>v;
vector<int>dp;
int k;
long long solve(int index=0)
{
    if(index>=n-1)return 0;
    if(index==n-2)return abs(v[n-1]-v[n-2]);
    if(dp[index]!=-1)return dp[index];
    long long ret=INT_MAX;
    for(int i=1;i<=k;i++)
    {
        if(index+i<n)
        ret=min(ret, solve(index+i)+abs(v[index+i]-v[index]));
    }
    return dp[index]=ret;
}
signed main() {
    khaled
    cin>>n;
    cin>>k;
    v.resize(n);
    dp.resize(n,-1);
    for(auto &val:v)
        cin>>val;
    cout<<solve();
}
