#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool valid(int i,int j,int n,int m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))+mod)%mod;}
long long fast_power(long long base,long long power,const long long &mod=INT64_MAX){
    if(power==0)return 1ll;long long d= fast_power(base,power/2)%mod;d=mul(d,d,mod);if(power&1)return mul(d,base,mod);else return d;}
long long mod_inverse_fermat(long long B,const long long&mod=1e9+7){ return fast_power(B,mod-2);}//mod is prime
int dx[]{1,-1,0,0,1,1,-1,-1};//0->4 normal,4->8 diagonal
int dy[]{0,0,1,-1,1,-1,1,-1};
#define int long long
/*--------------------------------------------------------------------------------------------------------------------*/
vector<vector<int>>dp;
long long solve(int i,int j,int n,int m,vector<vector<int>>&v)
{
    if(i==n||j==m||j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    long long res1=solve(i+1,j,n,m,v)+v[i][j];
    long long res2=solve(i+1,j+1,n,m,v)+v[i][j];
    long long res3=solve(i+1,j-1,n,m,v)+v[i][j];
    return dp[i][j]=max({res1, res2, res3});
}
signed main() {
    khaled
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>v(n,vector<int>(m));
        dp.clear();
        dp.resize(n,vector<int>(m,-1));
        for(auto &val:v)for(auto &i:val)cin>>i;
        int my_max=0;
        for(int j=0;j<m;j++)
            {
            my_max=max(my_max,solve(0,j,n,m,v));
            }
        cout<<my_max;
        if(t!=0)
          cout<<line;
    }
}

