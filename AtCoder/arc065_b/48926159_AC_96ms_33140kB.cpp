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
const int N=2e5+5;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=1e18+1;
int dx[]{1,-1,0,0,1,1,-1,-1};
int dy[]{0,0,1,-1,1,-1,1,-1};
const long double pi=3.14159265350979323846,eps=1e-8;
/*==============================================  KHALWSH  ==============================================*/
//g++ main.cpp -o main
//main.exe
vector<int>adj1[N];
vector<int>adj2[N];
int rep1[N];
int rep2[N];
bool vis [N];
void dfs(int node,int rep){
	rep1[node]=rep;
	vis[node]=true;
	for(auto &val:adj1[node]){
		if(!vis[val])dfs(val,rep);
	}
}void dfs2(int node,int rep){
	rep2[node]=rep;
	vis[node]=true;
	for(auto &val:adj2[node]){
		if(!vis[val])dfs2(val,rep);
	}
}
map<pair<int,int>,int>res;
signed main() {
    khaled
	int n,k,l;
	cin>>n>>k>>l;
	for(int i=0;i<k;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		adj1[a].emplace_back(b);
		adj1[b].emplace_back(a);
	}
	for(int i=0;i<l;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		adj2[a].emplace_back(b);
		adj2[b].emplace_back(a);
	}
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			dfs(i,i);
		}
	}
	memset(vis,0,sizeof vis);
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			dfs2(i,i);
		}
	}
	for(int i=0;i<n;i++){
		res[{rep1[i],rep2[i]}]++;
	}
	for(int i=0;i<n;i++){
		cout<<res[{rep1[i],rep2[i]}]<<" ";
	}
}