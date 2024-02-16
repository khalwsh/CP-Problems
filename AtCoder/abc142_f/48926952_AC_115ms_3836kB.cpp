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
//const int mod=1e9+7;
const int mod = 998244353;
const long long inf=1e9+1;
int dx[]{1,-1,0,0,1,1,-1,-1};
int dy[]{0,0,1,-1,1,-1,1,-1};
const double pi=3.14159265350979323846,eps=1e-8;
/*==============================================  KHALWSH  ==============================================*/
int n;
vector<int>adj[1001];
int CycleStart = -1,CycleEnd = -1;
int vis[1001];
bool finish = false;
int parent[1001];
void dfs(int node){
    vis[node]=1;
    for(auto &val:adj[node]){
        if(finish)return;
        if(vis[val]==0){
            parent[val]=node;
            dfs(val);
        }else if(vis[val]==1){
            finish = true;
            CycleStart = val;
            CycleEnd = node;
            return;
        }
        if(finish)return;
    }
    vis[node]=2;
}
set<int>CyclicNodes;
set<int>ForbiddenNodes;
void dfs2(int node){
    if(CyclicNodes.count(node)==0)return;
    if(ForbiddenNodes.count(node)==1)return;
    vis[node]=1;
    for(auto &val:adj[node]){
        if(vis[val]==1)finish=true;
        if(vis[val]==0)dfs2(val);
    }
    vis[node]=2;
}
signed main() {
    khaled
    cin>>n;
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].emplace_back(b);
    }
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            dfs(i);
            if(finish)break;
        }
    }
    if(CycleEnd==-1){
        cout<<-1<<line;
        exit(0);
    }
    CyclicNodes.insert(CycleStart);
    for(int i=CycleEnd;i!=CycleStart;i=parent[i]){
        CyclicNodes.insert(i);
    }
    memset(vis,0,sizeof vis);
    for(auto &val:CyclicNodes){
        ForbiddenNodes.insert(val);
        for(auto &i:CyclicNodes)vis[i]=false;
        finish = false;
        for(auto &i:CyclicNodes){
            if(ForbiddenNodes.count(i))continue;
            dfs2(i);
        }
        if(!finish){
            ForbiddenNodes.erase(val);
        }
    }
    vector<int>res;
    for(auto &val:CyclicNodes){
        if(!ForbiddenNodes.count(val))
            res.emplace_back(val);
    }
    cout<<res.size()<<line;
    for(auto &val:res)
        cout<<val+1<<line;
}