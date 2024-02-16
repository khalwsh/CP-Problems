#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//#include <ext/pb_ds/detail/standard_policies.hpp>//this file only make me able to use ordered set
using namespace __gnu_pbds;
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
//instead of less if write less_equal it will be considered as multiset,same as greater_equal
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// find_by_order-->get the index value, order_of_key-->how many smaller than key and with in set
const int N=1e5+5;
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
void dfs(int node,vector<bool>&vis,vector<int>adj[],stack<int>&finish_time){
    vis[node]=true;
    for(auto &val:adj[node]){
        if(!vis[val])
            dfs(val,vis,adj,finish_time);
    }
    finish_time.push(node);
}
void dfs2(int node,vector<bool>&vis,vector<int>adj[],vector<int>&res){
    res.emplace_back(node);
    vis[node]=true;
    for(auto &val:adj[node]){
        if(!vis[val])
            dfs2(val,vis,adj,res);
    }
}
signed main() {
    khaled
    while(true) {
        int n, m;
        cin >> n >> m;
        if(n==0&&m==0)break;
        vector<int> adj[n];
        vector<int> rev[n];
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            int way;
            cin>>way;
            x--, y--;
            if (x == y)continue;
            adj[x].emplace_back(y);
            rev[y].emplace_back(x);
            if(way==2)
                adj[y].emplace_back(x),rev[x].emplace_back(y);
        }
        vector<bool> vis(n, false);
        stack<int> finish_time;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                dfs(i, vis, adj, finish_time);
        }
        vector<int> res;
        int cnt = 0;
        for (int i = 0; i < n; i++)vis[i] = false;
        while (!finish_time.empty()) {
            int node = finish_time.top();
            finish_time.pop();
            if (vis[node])continue;
            cnt++;
            if (cnt == 2)break;
            dfs2(node, vis, rev, res);
        }
        cout << (res.size() != n ? 0 : 1) << line;
    }
}