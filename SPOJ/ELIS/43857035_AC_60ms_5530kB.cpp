#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool valid(int i,int j,int n,int m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const int&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const int&mod){return (((x%mod)+(y%mod))+mod)%mod;}
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
//#define int long long
/*--------------------------------------------------------------------------------------------------------------------*/
int n;
vector<int>v;
vector<vector<int>>dp;
long long lis(int index,int last_taken)
{
    if(index==n+1)
        return 0;
    long long res1=0;
    if(dp[index][last_taken]!=-1)return dp[index][last_taken];
    long long res2=lis(index+1,last_taken);
    if(v[index]>v[last_taken])
        res1=1ll+lis(index+1,index);
    return dp[index][last_taken]=max(res1,res2);
}
signed main() {
    khaled
    cin>>n;
    v.resize(n+1);
    v[0]=-1;
    for(int i=1;i<=n;i++)cin>>v[i];
    dp.resize(n+1,vector<int>(n+1,-1));
    cout<<lis(1,0);
}
