#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//#include <ext/pb_ds/detail/standard_policies.hpp>//this file only make me able to use ordered set
using namespace __gnu_pbds;
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool line_checking(long long a1,long long b1,long long a2,long long b2,long long a3,long long b3){return (a3-a1)*(b2-b1)==(a2-a1)*(b3-b1);}
bool valid(int i,int j,int n,int m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &mod=INT64_MAX){if(power==0)return 1ll;long long d= fast_power(base,power/2)%mod;d=mul(d,d,mod);if(power&1)return mul(d,base,mod);else return d;}
long long mod_inverse_fermat(long long B,const long long&mod=1e9+7){ return fast_power(B,mod-2,mod);}//mod is prime
vector<int>mod_inverse_for_range(int p){vector<int>inv(p,1);for(int i=2;i<p;i++) {inv[i] = ( p - (p / i) * inv[p % i] % p ) % p;}return inv;}//mod is prime
vector<long long>factorial(long long n,const long long& mod){vector<long long>v(n+1,1);for(int i=2;i<=n;i++)v[i]=mul(i,v[i-1],mod);return v;}
int dx[]{1,-1,0,0,1,1,-1,-1};//0->4 normal,4->8 diagonal
int dy[]{0,0,1,-1,1,-1,1,-1};
#define int long long
//instead of less if write less_equal it will be considered as multiset,same as greater_equal
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// find_by_order-->get the index value, order_of_key-->how many smaller than key and with in set
const int N=1e5+5;
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
vector<vector<int>>dp;
long long solve(int index,int state,int n,vector<pair<int,int>>&v)//state-->0 your prev still stand,1-->prev left,2--->right;
{
    if(index==n)return 0;
    if(dp[index][state]!=-1)return dp[index][state];
    int &res=dp[index][state];
    res=solve(index+1,0,n,v);
    if(state==0||state==1){
        if(v[index].first-v[index].second>v[index-1].first)
            res=max(res,solve(index+1,1,n,v)+1);
        if(v[index].first+v[index].second<v[index+1].first)
            res=max(res,solve(index+1,2,n,v)+1);
    }else{
        if(v[index].first-v[index].second>v[index-1].first+v[index-1].second)
            res=max(res,solve(index+1,1,n,v)+1);
        if(v[index].first+v[index].second<v[index+1].first)
            res=max(res,solve(index+1,2,n,v)+1);
    }
    return res;
}
signed main() {
    khaled
    int n;cin>>n;
    vector<pair<int,int>>v(n);
    for(auto &val:v)cin>>val.first>>val.second;
    sort(v.begin(),v.end());
    dp.resize(n,vector<long long>(3,-1));
    if(n==1)
    {
        cout<<1;
        exit(0);
    }
    else if(n==2){
        cout<<2;
        exit(0);
    }
    cout<<solve(1,1,n-1,v)+2<<line;
}