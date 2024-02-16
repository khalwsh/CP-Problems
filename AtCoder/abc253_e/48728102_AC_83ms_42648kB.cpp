#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int long long
#define double long double
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
bool valid(long long i,long long j,long long n,long long m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &m=INT64_MAX){if (power == 1 || power == 0)return base * power + (!power);long long res = (fast_power(base, power / 2, m) % m) % m;if (power & 1)return mul(base,mul(res,res,m),m);else return mul(res,res,m);}
int log2_floor(long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : 0;}
int power_of_2(int n){ return __builtin_popcountll(n)==1;}
bool line_checking(int a1,int b1,int a2,int b2,int a3,int b3) { return (b2-b1)*(a2-a3)==(b2-b3)*(a2-a1); }
pair<int,int> rotate(int i,int j,int n){ return make_pair(j,n-1-i); }
const int N=1e5+5;
//const int mod=1e9+7;
const int mod = 998244353;
const long long inf=8e18+1;
int dx[]{1,-1,0,0,1,1,-1,-1};
int dy[]{0,0,1,-1,1,-1,1,-1};
const double pi=3.14159265350979323846,eps=1e-8;
/*==============================================  KHALWSH  ==============================================*/
int n,m,k;
int dp[1000][5005];
int pref[5005];
signed main() {
    khaled
    cin>>n>>m>>k;
    if(k==0){
        int res = 0;
        cout<<fast_power(m,n,mod)<<line;
        exit(0);
    }
    for(int i=1;i<=m;i++)dp[0][i]=1;
    dp[0][0]=0;
    for(int i=0;i<=m;i++)pref[i]=dp[0][i];
    for(int i=1;i<=m;i++)pref[i]=add(pref[i],pref[i-1],mod);
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            int res=0;
            res = add(res,(j-k>0?pref[j-k]:0),mod);
            res = add(res,pref[m]-(min(m,j+k-1)>0?pref[min(j+k-1,m)]:0),mod);
            dp[i][j]=res;
        }
        for(int ii=1;ii<=m;ii++)pref[ii]=dp[i][ii];
        for(int ii=2;ii<=m;ii++)pref[ii]=add(pref[ii],pref[ii-1],mod);
    }
    int res = 0;
    dp[n-1][0]=0;
    for(auto &val:dp[n-1])res=add(res,val,mod);
    cout<<res<<line;
}