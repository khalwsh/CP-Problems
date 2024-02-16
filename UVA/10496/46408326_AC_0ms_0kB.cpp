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
const int N=1e7+1;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=2e17+1;
//__builtin_clzll(x): the number of zeros at the beginning of the number
//__builtin_ctzll(x): the number of zeros at the end of the number
//__builtin_popcountll(x): the number of ones in the number
//__builtin_parityll(x): the parity (even or odd) of the number of ones
/*=======================================================================================================*/
/*==============================================  KHALWSH  ==============================================*/
/*=======================================================================================================*/
int dist(int a,int b,int c,int d){
    return abs(c-a)+abs(d-b);
}
int dp[41][41][1<<10];
int vis[41][41][1<<10];
int tx=1;
int solve(int cur_x,int cur_y,int mask,int start,int end,vector<pair<int,int>>&v){
    if(__builtin_popcountll(mask)==0)return dist(cur_x,cur_y,start,end);
    int res=inf;
    int &ret=dp[cur_x+20][cur_y+20][mask];
    if(vis[cur_x+20][cur_y+20][mask]==tx)return ret;
    vis[cur_x+20][20+cur_y][mask]=tx;
    for(int i=0;i<v.size();i++){
        if((mask>>i)&1){
            res=min(res,solve(v[i].first,v[i].second,mask^(1<<i),start,end,v)
            +dist(cur_x,cur_y,v[i].first,v[i].second));
        }
    }
    return ret=res;
}
signed main() {
    khaled
    int t;
    cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        int start,end;
        cin>>start>>end;
        int k;
        cin>>k;
        vector<pair<int,int>>v(k);
        for(auto &val:v)cin>>val.first>>val.second;
        cout<<"The shortest path has length ";
        cout<<solve(start,end,(1<<k)-1,start,end,v)<<line;
        tx++;
    }
}
