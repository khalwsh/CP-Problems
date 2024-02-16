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
map<int,int>mp;
vector<long long>dp;
long long solve(int i,int n,vector<int>&v)
{
    if(i==0)return 0;
    else if(i==1)return mp[1];
    if(dp[i]!=-1)return dp[i];
    return dp[i]=max(solve(i-1,n,v),solve(i-2,n,v)+mp[i]*i);
}
signed main() {
    khaled
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &val:v)cin>>val;
    for(auto &val:v)mp[val]++;
    sort(v.begin(),v.end());
    dp.resize(*max_element(v.begin(),v.end())+1,-1);
    cout<<solve(*max_element(v.begin(),v.end()),n,v)<<line;
}

