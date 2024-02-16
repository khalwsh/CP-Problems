#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dx[]{1,-1,0,0,1,1,-1,-1};
int dy[]{0,0,1,-1,1,-1,1,-1};
const long double pi=3.14159265350979323846;
const long double eps=1e-9;
template<typename T>
using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
bool valid(long long i,long long j,long long n,long long m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &m=INT64_MAX){if (power == 1 || power == 0)return base * power + (!power);long long res = (fast_power(base, power / 2, m) % m) % m;if (power & 1)return mul(base,mul(res,res,m),m);else return mul(res,res,m);}
int log2_floor(long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : 0;}
int power_of_2(int n){ return __builtin_popcountll(n)==1;}
bool line_checking(long long a1,long long b1,long long a2,long long b2,long long a3,long long b3) {return (a3 - a1) * (b2 - b1) == (a2 - a1) * (b3 - b1);}
const int N=2e5+1;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=2e17+1;
/*=======================================================================================================*/
/*==============================================  KHALWSH  ==============================================*/
/*=======================================================================================================*/
vector<int>adj[401];
int dist[401];
int parent[401];
set<pair<int,int>>shortestPathEdges;
void dikstra(int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    pq.push({0,0});
    dist[0]=0;
    while(!pq.empty()){
        int node=pq.top().second;
        int cost=pq.top().first;
        pq.pop();
        if(cost!=dist[node])continue;
        for(auto &val:adj[node]){
            if(cost+1<dist[val]){
                dist[val]=cost+1;
                pq.push({dist[val],val});
                parent[val]=node;
            }
        }
    }
    int par=n-1;
    vector<int>path;
    while(par!=-1){
        path.emplace_back(par);
        par=parent[par];
    }
    reverse(path.begin(),path.end());
    for(int i=0;i<path.size()-1;i++){
        shortestPathEdges.insert(make_pair(path[i],path[i+1]));
    }
}
vector<pair<int,int>>edges;
int GetAns(int i,int n){
    vector<int>d(n,inf);
    queue<int>q;
    q.push(0);
    d[0]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto &val:adj[node]){
            if(make_pair(node,val)==edges[i])continue;
            if(d[val]==inf)d[val]=1+d[node],q.push(val);
        }
    }
    return (d[n-1]==inf?-1:d[n-1]);
}
signed main() {
    khaled
    int n,m;
    cin>>n>>m;
    memset(parent,-1,sizeof parent);
    for(auto &val:dist)val=inf;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].emplace_back(b);
        edges.emplace_back(a,b);
    }
    dikstra(n);
    if(dist[n-1]==inf){
        for(int i=0;i<m;i++){
            cout<<-1<<line;
        }
        exit(0);
    }
    for(int i=0;i<m;i++){
        if(shortestPathEdges.count(edges[i])){
            cout<<GetAns(i,n);
        }else
            cout<<dist[n-1];
        cout<<line;
    }
}
