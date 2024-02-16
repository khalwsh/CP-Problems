#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool line_checking(long long a1,long long b1,long long a2,long long b2,long long a3,long long b3){return (a3-a1)*(b2-b1)==(a2-a1)*(b3-b1);}
bool valid(int i,int j,int n,int m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &mod=INT64_MAX){if(power==0)return 1ll;long long d= fast_power(base,power/2)%mod;d=mul(d,d,mod);if(power&1)return mul(d,base,mod);else return d;}
long long mod_inverse_fermat(long long B,const long long&mod=1e9+7){ return fast_power(B,mod-2);}//mod is prime
int dx[]{1,-1,0,0,1,1,-1,-1};//0->4 normal,4->8 diagonal
int dy[]{0,0,1,-1,1,-1,1,-1};
#define int long long
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
const int mod=998244353;
vector<vector<long long>>dp;
long long solve(int i,int n,int digit)
{
    if(i == n){
        return 1;
    }
    int &ret = dp[i][digit];
    if(~ret) return ret;
    ret =0 ;
    for(int j = 1;j <= 9;++j){
        int x = abs(j - digit);
        if(x <= 1){
            ret += solve(i + 1 ,n, j) % mod;
            ret %= mod;
        }
    }
    return ret;
}
signed main(){
    khaled
    int n;
    cin>>n;
    long long res=0;
    dp.clear();
    dp.resize(n+1,vector<int>(10,-1));
    for(int i = 1;i <= 9;++i){
        res += solve(1 ,n, i) % mod;
        res %= mod;
    }
    cout<<res<<line;
}

