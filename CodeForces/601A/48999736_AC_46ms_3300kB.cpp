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
int dx[]{1,-1,0,0,1,1,-1,-1};
int dy[]{0,0,1,-1,1,-1,1,-1};
const double pi=3.14159265350979323846,eps=1e-8;
/*==============================================  KHALWSH  ==============================================*/
int n,m;
vector<int>bus[401];
vector<int>train[401];
int dist1[401];
int dist2[401];
int solve(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    pq.push({0,0});
    dist1[0]=0;
    while(!pq.empty()){
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(cost!=dist1[node])continue;
        for(auto &val:train[node]){
            if(dist1[val]>cost+1){
                dist1[val]=cost+1;
                pq.push({cost+1,val});
            }
        }
    }
    dist2[0]=0;
    pq.push({0,0});
    while(!pq.empty()){
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(cost!=dist2[node])continue;
        for(auto &val:bus[node]){
            if(dist2[val]>cost+1&&(val==n-1||dist1[val]!=cost+1)){
                dist2[val]=cost+1;
                pq.push({cost+1,val});
            }else if(dist2[val]>cost+1&&dist1[val]==cost+1){
                if(dist2[val]>cost+3){
                    dist2[val]=cost+3;
                    pq.push({cost+3,val});
                }
            }
        }
    }
    //cout<<dist1[n-1]<<" "<<dist2[n-1]<<line;
    return max(dist1[n-1],dist2[n-1]);
}
signed main() {
    khaled
    cin>>n>>m;
    for(auto &val:dist1)val = inf;
    for(auto &val:dist2)val = inf;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        train[a].emplace_back(b);
        train[b].emplace_back(a);
    }
    for(int i = 0;i<n;i++)sort(train[i].begin(),train[i].end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            auto it = lower_bound(train[i].begin(),train[i].end(),j);
            if(it==train[i].end()||*it!=j){
                bus[i].emplace_back(j);
                bus[j].emplace_back(i);
            }
        }
    }
    int res = solve();
    for(auto &val:dist1)val = inf;
    for(auto &val:dist2)val = inf;
    swap(train,bus);
    res = min(res,solve());
    cout<<(res==inf?-1:res)<<line;
}