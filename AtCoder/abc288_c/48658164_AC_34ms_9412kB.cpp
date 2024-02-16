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
const int N=5e5+5;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=2e18+1;
int dx[]{1,-1,0,0,1,1,-1,-1};
int dy[]{0,0,1,-1,1,-1,1,-1};
const double pi=3.14159265350979323846,eps=1e-8;
/*==============================================  KHALWSH  ==============================================*/
struct dsu{
    vector<int>parent,size;
    dsu(int n){
        size.resize(n,1);
        parent.resize(n,0);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int find(int child){
        return (parent[child]==child?child:parent[child]=find(parent[child]));
    }
    bool merge(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b)return false;
        if(size[a]>size[b])swap(a,b);
        size[b]+=size[a];
        parent[a]=b;
        return true;
    }
};
signed main() {
    khaled
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>vp(m);
    dsu d(n);
    int cnt=0;
    for(auto &val:vp) {
        cin >> val.first >> val.second;
        val.first--,val.second--;
        if(d.merge(val.first, val.second))continue;
        cnt++;
    }
    cout<<cnt;
}