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
const long double eps=1e-6;
#define int long long
template<typename T>
using ordered_set=tree<T,null_type,greater_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
long long derangement(int n){if(n == 0)return 1;if(n == 1)return 0;if(n == 2)return 1;return (n - 1)*(derangement(n - 1) + derangement(n - 2));}
bool line_checking(long long a1,long long b1,long long a2,long long b2,long long a3,long long b3){return (a3-a1)*(b2-b1)==(a2-a1)*(b3-b1);}
bool valid(long long i,long long j,long long n,long long m){return i>=0&&i<n&&j>=0&&j<m;}
long long safe_mul_mod(long long a,long long b,const long long &mod){long long res=0,y=a%mod;while(b>0){if(b&1){res=((res%mod)+(y%mod))%mod;}y=((y%mod)*(2ll%mod))%mod;b>>=1;}return (res%mod);}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &m=INT64_MAX){if (power == 1 || power == 0)return base * power + (!power);long long res = (fast_power(base, power / 2, m) % m) % m;if (power & 1)return mul(base,mul(res,res,m),m);else return mul(res,res,m);}
long long mod_inverse_fermat(long long B,const long long&mod=1e9+7){ return fast_power(B,mod-2,mod);}//mod is prime
vector<int>mod_inverse_for_range(int p){vector<int>inv(p,1);for(int i=2;i<p;i++) {inv[i] = ( p - (p / i) * inv[p % i] % p ) % p;}return inv;}//mod is prime
vector<long long>factorial(long long n,const long long& mod){vector<long long>v(n+1,1);for(int i=2;i<=n;i++)v[i]=mul(i,v[i-1],mod);return v;}
long long phi(long long n) {long long result = n;for (int i = 2; i * i <= n; i++) {if (n % i == 0) {while (n % i == 0)n /= i;result -= result / i;}}if (n > 1)result -= result / n;return result;}
bool power_of_two(int n) { n=abs(n); return n && !(n & (n - 1));}
const int N=1e6+1;
const int mod=1e9+7;
const long long inf=3e18;
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
stack<int>t;
void dfs(int node,vector<int>adj[],vector<int>&vis){
    vis[node]=true;
    for(auto &val:adj[node]){
      if(!vis[val])  dfs(val,adj,vis);
    }
    t.push(node);
}
bool cycle(int node,vector<int>adj[],vector<int>&vis){
    vis[node]=1;
    bool res=false;
    for(auto &val:adj[node]){
        if(vis[val]==0)res=res||cycle(val,adj,vis);
        else if(vis[val]==1){
            return res=true;
        }
    }
    vis[node]=2;
    return res;
}
signed main() {
    khaled
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].emplace_back(b);
    }
    vector<int>vis(n,0);
    for(int i=0;i<n;i++){
        if(cycle(i,adj,vis)){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    for(int i=0;i<n;i++)vis[i]=0;
    for(int i=0;i<n;i++){
        if(vis[i]==0)dfs(i,adj,vis);
    }
    while(!t.empty()){
        cout<<t.top()+1<<" ";
        t.pop();
    }
}