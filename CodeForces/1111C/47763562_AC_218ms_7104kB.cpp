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
/*=======================================================================================================*/
/*==============================================  KHALWSH  ==============================================*/
/*=======================================================================================================*/
// open file ------ notepad filename.cpp
// compile ------ g++ filename.cpp -o filename
// run ------ cp.exe
int n,k,a,b;
vector<int>v;
map<int,int>mp;
int get1(int target){
	int left=0,right=k-1;
	int res=inf;
	while(left<=right){
		int mid=left+(right-left)/2;
		if(v[mid]>=target){
			res=mid,right=mid-1;
		}else{
			left=mid+1;
		}
	}
	return res;
}
int get2(int target){
	int left=0,right=k-1;
	int res=inf;
	while(left<=right){
		int mid=left+(right-left)/2;
		if(v[mid]<=target){
			res=mid,left=mid+1;
		}else{
			right=mid-1;
		}
	}
	return res;
	
}
int solve(int left,int right){
	if(left==right){
		auto it=lower_bound(v.begin(),v.end(),left);
		if(it==v.end()||*it!=left)
           return a;
		return b*mp[left];
	}else{
		auto it=lower_bound(v.begin(),v.end(),left);
		if(it==v.end()||*it>right)return a;
        int first=get1(left);
		int last= get2(right);
		int mid=left+(right-left)/2;
		return min(b*(last-first+1)*(right-left+1),solve(left,mid)+solve(mid+1,right));
	}		
}
signed main() {
    khaled
	cin>>n>>k>>a>>b;
	v.resize(k);
	//2^n;
	for(auto &val:v)cin>>val,mp[val]++;
	sort(v.begin(),v.end());
	cout<<solve(1,(1ll<<n))<<line;
}