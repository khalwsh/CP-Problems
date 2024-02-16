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
const int N=2e5+5;
//const int mod=1e9+7;
const int mod = 998244353;
const long long inf=8e18+1;
int dx[]{1,-1,0,0,1,1,-1,-1};
int dy[]{0,0,1,-1,1,-1,1,-1};
const double pi=3.14159265350979323846,eps=1e-8;
/*==============================================  KHALWSH  ==============================================*/
vector<int>adj[N];
vector<int>vis(N,2);
bool work=true;
int a=0,b=0;
void dfs(int node,int color){
    vis[node]=color;
    if(color==0)a++;
    else b++;
    for(auto &val:adj[node]){
        if(vis[val]==2)dfs(val,1-color);
        if(vis[val]==color)work=false;
    }
}
signed main() {
    khaled
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int c,d;
        cin>>c>>d;
        c--,d--;
        adj[c].emplace_back(d);
        adj[d].emplace_back(c);
    }
    int res = n*(n-1)/2;
    res-=m;
    for(int i=0;i<n;i++){
        if(vis[i]==2) {
            dfs(i, 0);
            res -= (a * (a - 1) / 2);
            res -= (b * (b - 1)) / 2;
            a=0,b=0;
        }
    }
    if(!work){
        cout<<0<<line;
    }
    else{
        cout<<res<<line;
    }
}