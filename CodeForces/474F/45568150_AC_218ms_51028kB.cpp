#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dx[]{1,-1,0,0,1,1,-1,-1};//0->4 normal,4->8 diagonal
int dy[]{0,0,1,-1,1,-1,1,-1};
const long double pi=3.14159265350979323846;
const long double eps=1e-9;
#define int long long
template<typename T>
using ordered_set=tree<T,null_type,greater_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
bool line_checking(long long a1,long long b1,long long a2,long long b2,long long a3,long long b3){return (a3-a1)*(b2-b1)==(a2-a1)*(b3-b1);}
bool valid(long long i,long long j,long long n,long long m){return i>=0&&i<n&&j>=0&&j<m;}
long long safe_mul_mod(long long a,long long b,const long long &mod){long long res=0,y=a%mod;while(b>0){if(b&1){res=((res%mod)+(y%mod))%mod;}y=((y%mod)*(2ll%mod))%mod;b>>=1;}return (res%mod);}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &m=INT64_MAX){if (power == 1 || power == 0)return base * power + (!power);long long res = (fast_power(base, power / 2, m) % m) % m;if (power & 1)return mul(base,mul(res,res,m),m);else return mul(res,res,m);}
long long mod_inverse_fermat(long long B,const long long&mod){ return fast_power(B,mod-2,mod);}//mod is prime
vector<int>mod_inverse_for_range(int n,int p){vector<int>inv(n+1,1);for(int i=2;i<=n;i++) {inv[i] = ( p - (p / i) * inv[p % i] % p ) % p;}return inv;}//mod is prime
vector<long long>factorial(long long n,const long long& mod){vector<long long>v(n+1,1);for(int i=2;i<=n;i++)v[i]=mul(i,v[i-1],mod);return v;}
long long phi(long long n) {long long result = n;for (int i = 2; i * i <= n; i++) {if (n % i == 0) {while (n % i == 0)n /= i;result -= result / i;}}if (n > 1)result -= result / n;return result;}
bool power_of_two(int n) { n=abs(n); return n && !(n & (n - 1));}
int log2_floor(long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;}
const int N=1e5+1;
const int mod=1e9+7;
const long long inf=6e18;
//__builtin_clzll(x): the number of zeros at the beginning of the number
//__builtin_ctzll(x): the number of zeros at the end of the number
//__builtin_popcountll(x): the number of ones in the number
//__builtin_parityll(x): the parity (even or odd) of the number of ones
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
int k=25;
int query(int l,int r,vector<vector<int>>&table,bool flag){
    if(l>r)swap(l,r);
    int log= log2_floor(r-l+1);
    return (flag?__gcd(table[log][l],table[log][r-(1<<log)+1]):min(table[log][l],table[log][r-(1<<log)+1]));
}
vector<vector<int>>mn_table,gcd_table;
void buildMin(int n){
    for(int i=1;i<=k;i++){
        for(int j=0;j+(1<<i)<=n;j++){
            mn_table[i][j]=min(mn_table[i-1][j],mn_table[i-1][j+(1<<(i-1))]);
        }
    }
}
void buildGcd(int n){
    for(int i=1;i<=k;i++){
        for(int j=0;j+(1<<i)<=n;j++){
            gcd_table[i][j]=__gcd(gcd_table[i-1][j],gcd_table[i-1][j+(1<<(i-1))]);
        }
    }
}
int repetation(int l,int r,map<int,vector<int>>&mp,int mn){
    auto low= lower_bound(mp[mn].begin(),mp[mn].end(),l);
    auto up= upper_bound(mp[mn].begin(),mp[mn].end(),r);
    up--;
    if(low==mp[mn].end())return 0;
    if(*up<l)return 0;
    if(*low>r)return 0;
    return up-low+1;
}
signed main() {
    khaled
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &val:v)cin>>val;
    mn_table.resize(k+1,vector<int>(n));
    gcd_table.resize(k+1,vector<int>(n));
    std::copy(v.begin(),v.end(),mn_table[0].begin());
    std::copy(v.begin(),v.end(),gcd_table[0].begin());
    buildMin(n);
    buildGcd(n);
    map<int,vector<int>>adj;
    for(int i=0;i<n;i++){
        adj[v[i]].emplace_back(i);
    }
    int m;
    cin>>m;
    while(m--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        int mn= query(l,r,mn_table,false);
        int gcd=query(l,r,gcd_table,true);
        int rep= repetation(l,r,adj,mn);
        //cout<<mn<<" "<<gcd<<" "<<rep<<line;
        if(mn!=gcd){
            cout<<r-l+1<<line;
        }else{
            cout<<r-l+1-rep<<line;
        }
    }
}