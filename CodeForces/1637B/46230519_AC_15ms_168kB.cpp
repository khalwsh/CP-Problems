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
const int N=1e5+1;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=2e17;
//__builtin_clzll(x): the number of zeros at the beginning of the number
//__builtin_ctzll(x): the number of zeros at the end of the number
//__builtin_popcountll(x): the number of ones in the number
//__builtin_parityll(x): the parity (even or odd) of the number of ones
/*=======================================================================================================*/
/*==============================================  KHALWSH  ==============================================*/
/*=======================================================================================================*/
int dp[101][101];
int get_mex(int l,int r,vector<int>&v){
    int res=0;
    set<int>s;
    for(int i=l;i<=r;i++)s.insert(v[i]);
    for(auto &val:s){
        if(res==val)res++;
        else break;
    }
    return res;
}
int arr[101][101];
int solve(int start,int end,vector<int>&v){
    if(start==end+1)return 0;
    int res=0;
    int &ret=dp[start][end];
    if(~ret)return ret;
    for(int i=start;i<=end;i++){
        res=max(res,arr[start][i]+1+solve(i+1,end,v));
    }
    return ret=res;
}
signed main() {
    khaled
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(auto &val:v)cin>>val;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                arr[i][j]= get_mex(i,j,v);
            }
        }
        memset(dp,-1,sizeof dp);
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                res+=solve(i,j,v);
            }
        }
        cout<<res<<line;
    }
}