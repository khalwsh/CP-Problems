#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dx[]{1,-1,0,0,1,1,-1,-1};//0->4 normal,4->8 diagonal
int dy[]{0,0,1,-1,1,-1,1,-1};
const long double pi=3.14159265350979323846;
const long double eps=1e-9;
#define int long long
template<typename T>
using ordered_set=tree<T,null_type,greater_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
bool line_checking(long long a1,long long b1,long long a2,long long b2,long long a3,long long b3){return (a3-a1)*(b2-b1)==(a2-a1)*(b3-b1);}
bool valid(long long i,long long j,long long n,long long m){return i>=0&&i<n&&j>=0&&j<m;}
long long safe_mul_mod(long long a,long long b,const long long &mod){long long res=0,y=a%mod;while(b>0){if(b&1){res=((res%mod)+(y%mod))%mod;}y=((y%mod)*(2ll%mod))%mod;b>>=1;}return (res%mod);}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &m=INT64_MAX){if (power == 1 || power == 0)return base * power + (!power);long long res = (fast_power(base, power / 2, m) % m) % m;if (power & 1)return mul(base,mul(res,res,m),m);else return mul(res,res,m);}
long long mod_inverse_fermat(long long B,const long long&mod){ return fast_power(B,mod-2,mod);}//mod is prime
vector<int>mod_inverse_for_range(int n,int p){vector<int>inv(n+1,1);for(int i=2;i<=n;i++) {inv[i] = ( p - (p / i) * inv[p % i] % p ) % p;}return inv;}//mod is prime
vector<long long>factorial(long long n,const long long& mod){vector<long long>v(n+1,1);for(int i=2;i<=n;i++)v[i]=mul(i,v[i-1],mod);return v;}
long long phi(long long n) {long long result = n;for (int i = 2; i * i <= n; i++) {if (n % i == 0) {while (n % i == 0)n /= i;result -= result / i;}}if (n > 1)result -= result / n;return result;}
bool power_of_two(int n) { n=abs(n); return n && !(n & (n - 1));}
int log2_floor(long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;}
const int N=1e6+1;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=6e18;
//__builtin_clzll(x): the number of zeros at the beginning of the number
//__builtin_ctzll(x): the number of zeros at the end of the number
//__builtin_popcountll(x): the number of ones in the number
//__builtin_parityll(x): the parity (even or odd) of the number of ones
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
int dp[101];
int dfs(int node,vector<int>adj[]){
    int &res=dp[node];
    if(~res)return res;
    res=0;
    for(auto &val:adj[node]){
        res=max(res,1+dfs(val,adj));
    }
    return res;
}
int dp2[101];
int build(int node,vector<int>adj[]){
    if(~dp2[node])return dp2[node];
    int res=(adj[node].empty()?node:inf);
    for(auto &val:adj[node]){
       if(dp[node]==1+dfs(val,adj)){
           res=min(res,build(val,adj));
       }
    }
    return dp[node]=res;
}
signed main() {
    khaled
    int t=1;
    while(true){
        int n;
        cin>>n;
        if(t!=1)cout<<line;
        for(int i=0;i<=n;i++)dp2[i]=-1;
        for(int i=0;i<=n;i++)dp[i]=-1;
        if(!n)break;
        int s;
        cin>>s;
        s--;
        vector<int>adj[n];
        while(true){
            int a,b;
            cin>>a>>b;
            a--,b--;
            if(a==-1&&b==-1)break;
            adj[a].emplace_back(b);
        }
        int longest_path=dfs(s,adj);
        int node= build(s,adj);
        if(node==inf)node=s;
        cout<<"Case "<<t++<<": The longest path from "<<s+1<<" has length "<<longest_path<<", finishing at "<<node+1<<".";
        cout<<line;
    }
}