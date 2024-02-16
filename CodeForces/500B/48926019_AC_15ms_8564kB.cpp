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
int n;
vector<int>adj[N];
int v [301];
vector<vector<int>>comps;
bool vis[301];
vector<int>temp;
int id[301];
int uniqueId = 0;
void dfs(int node){
	vis[node]=true;
	id[node]=uniqueId;
	temp.emplace_back(node);
	for(auto &val:adj[node]){
		if(vis[val])continue;
		dfs(val);
	}
}
signed main() {
    khaled
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>v[i];
		v[i]--;
	}
	for(int i=0;i<n;i++){
		for(int j = 0;j<n;j++){
			char x;
			cin>>x;
			if(x=='1'){
				adj[v[i]].emplace_back(v[j]);
				adj[v[j]].emplace_back(v[i]);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			dfs(i);
			sort(temp.rbegin(),temp.rend());
			comps.emplace_back(temp);
			temp.clear();
			uniqueId++;
		}
	}
	for(int i=0;i<n;i++){
		cout<<comps[id[v[i]]].back()+1<<" ";
		comps[id[v[i]]].pop_back();
	}
}