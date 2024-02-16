#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool line_checking(long long a1,long long b1,long long a2,long long b2,long long a3,long long b3){return (a3-a1)*(b2-b1)==(a2-a1)*(b3-b1);}
bool valid(int i,int j,int n,int m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &mod=INT64_MAX){if(power==0)return 1ll;long long d= fast_power(base,power/2)%mod;d=mul(d,d,mod);if(power&1)return mul(d,base,mod);else return d;}
long long mod_inverse_fermat(long long B,const long long&mod=1e9+7){ return fast_power(B,mod-2,mod);}//mod is prime
vector<int>mod_inverse_for_range(int p){vector<int>inv(p,1);for(int i=2;i<p;i++) {inv[i] = ( p - (p / i) * inv[p % i] % p ) % p;}return inv;}//mod is prime
vector<long long>factorial(long long n,const long long& mod){vector<long long>v(n+1,1);for(int i=2;i<=n;i++)v[i]=mul(i,v[i-1],mod);return v;}
int dx[]{1,-1,0,0,1,1,-1,-1};//0->4 normal,4->8 diagonal
int dy[]{0,0,1,-1,1,-1,1,-1};
#define int long long
const int N=1e5+5;
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
vector<vector<int>>dp;
long long solve(int index,int weight,int n,vector<pair<int,int>>&vp){
    if(index==n)return 0;
    if(weight<0)return -1e9;
    if(dp[index][weight]!=-1)return dp[index][weight];
    long long res1=solve(index+1,weight,n,vp);
    long long res2=0;
    if(weight-vp[index].second>=0)
      res2=solve(index+1,weight-vp[index].second,n,vp)+vp[index].first;
    return dp[index][weight]=max(res1,res2);
}
signed main() {
    khaled
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>>vp(n);
        for(auto &val:vp)cin>>val.first>>val.second;
        dp.clear();
        int m;
        cin>>m;
        long long res=0;
        dp.resize(1001,vector<int>(40,-1));
        for(int i=0;i<m;i++){
           int x;
           cin>>x;
           res+=solve(0,x,n,vp);
        }
        cout<<res<<line;
    }
}