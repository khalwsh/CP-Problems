#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int long long
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
bool valid(long long i,long long j,long long n,long long m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &m=INT64_MAX){if (power == 1 || power == 0)return base * power + (!power);long long res = (fast_power(base, power / 2, m) % m) % m;if (power & 1)return mul(base,mul(res,res,m),m);else return mul(res,res,m);}
int log2_floor(long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : 0;}
int power_of_2(int n){ return __builtin_popcountll(n)==1;}
bool line_checking(int a1,int b1,int a2,int b2,int a3,int b3) { return (b2-b1)*(a2-a3)==(b2-b3)*(a2-a1); }
pair<int,int> rotate(int i,int j,int n){ return make_pair(j,n-1-i); }
const int N=1e5+5;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=2e17+1;
int dx[]{1,-1,0,0,1,1,-1,-1};
int dy[]{0,0,1,-1,1,-1,1,-1};
const long double pi=3.14159265350979323846,eps=1e-9;
/*==============================================  KHALWSH  ==============================================*/
string n;
int dp[17][17][2][2];
int tx=1;
int vis[17][17][2][2];
int solve(int index,int pref,bool PrefCanTake,bool tight){
    if(index==n.size()) {
        //cout<<pref<<line;
        return pref;
    }
    if(vis[index][pref][PrefCanTake][tight]==tx)return dp[index][pref][PrefCanTake][tight];
    vis[index][pref][PrefCanTake][tight]=tx;
    int lim=(tight?9:n[index]-'0');
    int res=0;
    for(int i=0;i<=lim;i++){
        res+=solve(index+1,pref+(PrefCanTake&&i==1?1:0),PrefCanTake&&i==1,tight||i<n[index]-'0');
    }
    return dp[index][pref][PrefCanTake][tight]= res;
}
signed main() {
    khaled
    cin>>n;
    int res=0;
    for(int i=1;i<=n.size();i++){
        if(i==n.size()){
            res+=solve(0,0,true,false);
        }else{
            string temp;
            int tt=i;
            while(tt--)temp+='9';
            string save=n;
            n=temp;
            res+=solve(0,0,true,false);
            n=save;
        }
        tx++;
    }
    cout<<res<<line;
}