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
const int N=2e5+1;
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
long double mat[31][31];
int n;
int m,p,a,b;
long double dp[31][1<<10];
int vis[31][1<<10];
int tx=1;
long double solve(int cur_city,int mask,vector<long double>&horses){
    if(cur_city==b)return 0.0;
    if(mask==0)return 1e11;
    long double res=1e11;
    long double &ret=dp[cur_city][mask];
    if(vis[cur_city][mask]==tx)return ret;
    vis[cur_city][mask]=tx;
    for(int i=0;i<n;i++){
        if(mask&(1<<i)){
            for(int j=0;j<m;j++){
                if(mat[cur_city][j]!=inf){
                    res=min(res,solve(j,mask^(1<<i),horses)+mat[cur_city][j]/horses[i]);
                }
            }
        }
    }
    return ret = res;
}
signed main() {
    khaled
    while(true){
        cin>>n>>m>>p>>a>>b;
        if(!n&&!m)break;
        vector<long double>horses(n);
        for(auto &val:mat)for(auto &i:val)i=inf;
        for(auto &val:horses)cin>>val;
        a--,b--;
        for(int i=0;i<p;i++){
            int x,y;
            cin>>x>>y;
            x--,y--;
            cin>>mat[x][y];
            mat[y][x]=mat[x][y];
        }
        cout<<fixed<<showpoint<<setprecision(12);
        long double res=solve(a,(1<<n)-1,horses);
        if(res==1e11){
            cout<<"Impossible";
        }else
            cout<<res;
        cout<<line;
        tx++;
    }
}