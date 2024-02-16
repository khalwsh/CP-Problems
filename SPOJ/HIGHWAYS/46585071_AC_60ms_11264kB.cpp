//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
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

signed main() {
    khaled
    int t;
    cin>>t;
    while(t--){
     int n,m,a,b;
     cin>>n>>m>>a>>b;
     a--,b--;
     vector<pair<int,int>>adj[n];
     for(int i=0;i<m;i++){
         int x,y;
         cin>>x>>y;
         int cost;cin>>cost;
         x--,y--;
         adj[x].emplace_back(y,cost);
         adj[y].emplace_back(x,cost);
     }
     vector<int>dist(n,inf);
     dist[a]=0;
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
     pq.push({0,a});
     while(!pq.empty()){
         int cost=pq.top().first;
         int node=pq.top().second;
         pq.pop();
         if(cost!=dist[node])continue;
         for(auto &val:adj[node]){
             if(cost+val.second<dist[val.first]){
                 dist[val.first]=val.second+cost;
                 pq.push({dist[val.first],val.first});
             }
         }
     }
     cout<<(dist[b]!=inf? to_string(dist[b]):"NONE")<<line;
    }
}