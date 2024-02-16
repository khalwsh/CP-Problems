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
int SafeMul(int a,int b,int m){if(b==0)return 0;int res = SafeMul(a,b/2,m);res = add(res,res,m);if(b&1)return add(res,a,m);else return res;}
long long fast_power(long long base,long long power,const long long &m=INT64_MAX){if (power == 1 || power == 0)return base * power + (!power);long long res = (fast_power(base, power / 2, m) % m) % m;if (power & 1)return mul(base,mul(res,res,m),m);else return mul(res,res,m);}
int log2_floor(long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : 0;}
int power_of_2(int n){ return __builtin_popcountll(n)==1;}
bool line_checking(int a1,int b1,int a2,int b2,int a3,int b3) { return (b2-b1)*(a2-a3)==(b2-b3)*(a2-a1); }
pair<int,int> rotate(int i,int j,int n){ return make_pair(j,n-1-i); }
const int N = 5e5+5;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=1e18+1;
int dx[]{2,2,-2,-2,1,-1,1,-1};
int dy[]{1,-1,1,-1,2,2,-2,-2};
const double pi=3.14159265350979323846,eps=1e-8;
/*==============================================  KHALWSH  ==============================================*/
void dfs(int node,int parent,vector<bool>&vis,vector<int>adj[],vector<int>&time,vector<int>&low,vector<vector<int>>&res,int &counter)
{
    vis[node]=true;
    time[node]=counter;
    counter++;
    low[node]=time[node];
    for(auto &val:adj[node])
    {
        if(!vis[val])
            dfs(val,node,vis,adj,time,low,res,counter);
        if(val!=parent)
            low[node]=min(low[node],low[val]);
        if(time[node]<low[val])
            res.emplace_back(vector<int>{node,val});
    }

}
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<int>adj[n];
    for(auto &val:connections)
    {
        adj[val[0]].emplace_back(val[1]);
        adj[val[1]].emplace_back(val[0]);
    }
    vector<int>time(n,0),low(n,INT_MAX);
    vector<vector<int>>res;
    vector<bool>vis(n,false);
    int c=0;
    dfs(0,-1,vis,adj,time,low,res,c);
    return res;
}
vector<int>adj[N];
int res = 0;
vector<int>nodes;
bool vis[N];
void dfs2(int node,int par){
    vis[node]=true;
    res++;
    nodes.emplace_back(node);
    for(auto &val:adj[node]){
        if(!vis[val])dfs2(val,node);
    }
}
signed main() {
    khaled
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edges.emplace_back(vector<int>{a,b});
    }
    vector<vector<int>>cons = criticalConnections(n,edges);
    set<pair<int,int>>bridges;
    for(auto &val:cons){
        bridges.insert({val[0],val[1]});
        bridges.insert({val[1],val[0]});
    }
    for(auto &val:edges){
        if(bridges.count({val[0],val[1]}))continue;
        adj[val[0]].emplace_back(val[1]);
        adj[val[1]].emplace_back(val[0]);
    }
    dfs2(0,-1);
    cout<<res<<line;
}