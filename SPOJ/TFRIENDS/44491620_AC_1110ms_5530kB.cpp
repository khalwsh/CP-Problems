#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//#include <ext/pb_ds/detail/standard_policies.hpp>//this file only make me able to use ordered set
using namespace __gnu_pbds;
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<vector<long long>>dp_nCr(100,vector<long long>(100,-1));
long long nCr(long long n,long long r){if(r == 0 || r == n)return 1;if(r == 1 || r == n - 1)return n;if(dp_nCr[n][r]!=-1)return dp_nCr[n][r]; return dp_nCr[n][r]= nCr(n - 1, r) + nCr(n - 1, r - 1);}
long long number_of_ways_to_choose_permutation_that_ith_index_not_equal_i(int n){if(n == 0)return 1;if(n == 1)return 0;if(n == 2)return 1;return (n - 1)*(number_of_ways_to_choose_permutation_that_ith_index_not_equal_i(n - 1) + number_of_ways_to_choose_permutation_that_ith_index_not_equal_i(n - 2));}
bool line_checking(long long a1,long long b1,long long a2,long long b2,long long a3,long long b3){return (a3-a1)*(b2-b1)==(a2-a1)*(b3-b1);}
bool valid(int i,int j,int n,int m){return i>=0&&i<n&&j>=0&&j<m;}
long long safe_mul_mod(long long a,long long b,const long long &mod){long long res=0,y=a%mod;while(b>0){if(b&1){res=((res%mod)+(y%mod))%mod;}y=((y%mod)*(2ll%mod))%mod;b>>=1;}return (res%mod);}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &m=INT64_MAX){if (power == 1 || power == 0)return base * power + (!power);long long res = (fast_power(base, power / 2, m) % m) % m;if (power & 1)return mul(base,mul(res,res,m),m);else return mul(res,res,m);}
long long mod_inverse_fermat(long long B,const long long&mod=1e9+7){ return fast_power(B,mod-2,mod);}//mod is prime
vector<int>mod_inverse_for_range(int p){vector<int>inv(p,1);for(int i=2;i<p;i++) {inv[i] = ( p - (p / i) * inv[p % i] % p ) % p;}return inv;}//mod is prime
vector<long long>factorial(long long n,const long long& mod){vector<long long>v(n+1,1);for(int i=2;i<=n;i++)v[i]=mul(i,v[i-1],mod);return v;}
int dx[]{1,-1,0,0,1,1,-1,-1};//0->4 normal,4->8 diagonal
int dy[]{0,0,1,-1,1,-1,1,-1};
const long double pi=3.14159265350979323846;
const long double Eps=1e-10;
#define int long long
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N=2e5+2;
const int mod=1e9+7;
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
void dfs(int node,vector<int>adj[],vector<bool>&vis,stack<int>&topo){
    vis[node]=true;
    for(auto &val:adj[node]){
        if(!vis[val])dfs(val,adj,vis,topo);
    }
    topo.push(node);
}
void dfs2(int node,vector<bool>&vis,vector<int>adj[]){
    vis[node]=true;
    for(auto &val:adj[node]){
        if(!vis[val])dfs2(val,vis,adj);
    }
}
signed main() {
    khaled
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>adj[n],rev[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char ch;
                cin>>ch;
                if(ch=='Y')
                    adj[i].emplace_back(j),rev[j].emplace_back(i);
            }
        }
        vector<bool>vis(n,false);
        stack<int>topo;
        for(int i=0;i<n;i++){
            if(!vis[i])dfs(i,adj,vis,topo);
        }
        int res=0;
        for(int i=0;i<n;i++)vis[i]=false;
        while(!topo.empty()){
            int node=topo.top();
            topo.pop();
            if(vis[node])continue;
            res++;
            dfs2(node,vis,rev);
        }
        cout<<res<<line;
    }
}