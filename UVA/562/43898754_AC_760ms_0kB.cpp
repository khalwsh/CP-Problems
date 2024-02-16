#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool valid(int i,int j,int n,int m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &mod=INT64_MAX){
    if(power==0)return 1ll;long long d= fast_power(base,power/2)%mod;d=mul(d,d,mod);if(power&1)return mul(d,base,mod);else return d;}
long long mod_inverse_fermat(long long B,const long long&mod=1e9+7){ return fast_power(B,mod-2);}//mod is prime
int dx[]{1,-1,0,0,1,1,-1,-1};//0->4 normal,4->8 diagonal
int dy[]{0,0,1,-1,1,-1,1,-1};
#define int long long
/*--------------------------------------------------------------------------------------------------------------------*/
long long solve(int index,int n,vector<int>&v,int cur_sum,vector<vector<int>>&dp,long long summation)
{
    if(index==n)
    {
       return abs(summation-cur_sum-cur_sum);
    }
    if(dp[index][cur_sum]!=-1)return dp[index][cur_sum];
    long long res1=solve(index+1,n,v,cur_sum+v[index],dp,summation);
    long long res2= solve(index+1,n,v,cur_sum,dp,summation);
    return dp[index][cur_sum]=min(res1,res2);
}
signed main() {
    khaled
    int n;
    cin>>n;
    while(n--)
    {
        int m;
        cin>>m;
        vector<int>v(m);
        for(auto &val:v)
            cin>>val;
        long long summation=0;
        vector<vector<int>>dp(m,vector<int>(50001,-1));
        for(auto &val:v)
            summation+=val;
        cout<<solve(0,m,v,0,dp,summation)<<line;
    }
}

