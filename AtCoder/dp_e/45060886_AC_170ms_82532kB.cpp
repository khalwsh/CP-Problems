#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
long long derangement(int n){if(n == 0)return 1;if(n == 1)return 0;if(n == 2)return 1;return (n - 1)*(derangement(n - 1) + derangement(n - 2));}
bool line_checking(long long a1,long long b1,long long a2,long long b2,long long a3,long long b3){return (a3-a1)*(b2-b1)==(a2-a1)*(b3-b1);}
bool valid(long long i,long long j,long long n,long long m){return i>=0&&i<n&&j>=0&&j<m;}
long long safe_mul_mod(long long a,long long b,const long long &mod){long long res=0,y=a%mod;while(b>0){if(b&1){res=((res%mod)+(y%mod))%mod;}y=((y%mod)*(2ll%mod))%mod;b>>=1;}return (res%mod);}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &m=INT64_MAX){if (power == 1 || power == 0)return base * power + (!power);long long res = (fast_power(base, power / 2, m) % m) % m;if (power & 1)return mul(base,mul(res,res,m),m);else return mul(res,res,m);}
long long mod_inverse_fermat(long long B,const long long&mod=1e9+7){ return fast_power(B,mod-2,mod);}//mod is prime
vector<int>mod_inverse_for_range(int n,int p){vector<int>inv(n+1,1);for(int i=2;i<n+1;i++) {inv[i] = ( p - (p / i) * inv[p % i] % p ) % p;}return inv;}//mod is prime
vector<long long>factorial(long long n,const long long& mod){vector<long long>v(n+1,1);for(int i=2;i<=n;i++)v[i]=mul(i,v[i-1],mod);return v;}
long long NCR_MOD(long long n, long long r,vector<long long>&fact,const long long&mod){return mul(mul(fact[n], mod_inverse_fermat(fact[n - r], mod), mod), mod_inverse_fermat(fact[r], mod), mod);}
long long phi(long long n) {long long result = n;for (int i = 2; i * i <= n; i++) {if (n % i == 0) {while (n % i == 0)n /= i;result -= result / i;}}if (n > 1)result -= result / n;return result;}
long double NCR_LINEAR_TIME(long long n,long long r){if(r>n)return 0;if(r==0||r==n){return 1;}if(r==1||r==n-1)return n;return NCR_LINEAR_TIME(n-1,r-1)*(long double)n/r;}
bool power_of_two(int n) { n=abs(n);  return n && !(n & (n - 1));}
int dx[]{1,-1,0,0,1,1,-1,-1};//0->4 normal,4->8 diagonal
int dy[]{0,0,1,-1,1,-1,1,-1};
const long double pi=3.14159265350979323846;
const long double Eps=1e-10;
#define int long long
template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N=1e5+1;
const int mod=1e9+7;
const long long inf=1e17;
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
int dp[101][100001];
int solve(int index,vector<pair<int,int>>&vp,int target_money){
    if(target_money<0){
        return 0;
    }
    if(index==vp.size()){
        if(target_money<=0)return 0;
        else return inf;
    }
    int &ret=dp[index][target_money];
    if(~ret)return ret;
    int res1=solve(index+1,vp,target_money-vp[index].second)+vp[index].first;
    int res2=solve(index+1,vp,target_money);
    return ret = min(res1,res2);
}
signed main() {
    khaled
    int n,w;
    cin>>n>>w;
    vector<pair<int,int>>vp(n);
    for(auto &val:vp)cin>>val.first>>val.second;
    int sum=0;
    for(auto &val:vp)sum+=val.second;
    int left=0,right=sum;
    int res=0;
    memset(dp,-1,sizeof(dp));
    while(left<=right){
        int mid=left+(right-left)/2;
        if(solve(0,vp,mid)<=w){
            res=mid,left=mid+1;
        }else
            right=mid-1;
    }
    cout<<res<<line;
}