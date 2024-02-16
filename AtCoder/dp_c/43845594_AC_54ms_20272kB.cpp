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
vector<vector<int>>v;
vector<vector<int>>dp;
long long solve(int index,int last_taken)
{
    if(index==0){
        if(last_taken==0)
            return max({v[index][1],v[index][2]});
        else if(last_taken==1)
            return max({v[index][0],v[index][2]});
        else if(last_taken==2)
            return max({v[index][1],v[index][0]});
        return *max_element(v[0].begin(),v[0].end());
    }
    if(dp[index][last_taken]!=-1)return dp[index][last_taken];
    long long take1=0,take2=0,take3=0;
    if(last_taken!=0)
        take1=solve(index-1,0)+v[index][0];
    if(last_taken!=1)
        take2=solve(index-1,1)+v[index][1];
    if(last_taken!=2)
        take3=solve(index-1,2)+v[index][2];
    return dp[index][last_taken]=max({take1,take2,take3});
}
signed main() {
    khaled
    cin>>n;
    v.resize(n);
    dp.resize(n);
    for(auto &val:v)val.resize(3);
    for(auto &val:dp)val.resize(4,-1);
    for(auto &val:v)for(auto &i:val)cin>>i;
    cout<<solve(n-1,3);
}
