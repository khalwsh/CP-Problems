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
const long double Eps=1e-10;
#define int long long
template<typename T>
using ordered_set=tree<T,null_type,greater_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
vector<vector<long long>>dp_nCr(100,vector<long long>(100,-1));
long long nCr(long long n,long long r){if(r == 0 || r == n)return 1;if(r == 1 || r == n - 1)return n;if(dp_nCr[n][r]!=-1)return dp_nCr[n][r]; return dp_nCr[n][r]= nCr(n - 1, r) + nCr(n - 1, r - 1);}
long long derangement(int n){if(n == 0)return 1;if(n == 1)return 0;if(n == 2)return 1;return (n - 1)*(derangement(n - 1) + derangement(n - 2));}
bool line_checking(long long a1,long long b1,long long a2,long long b2,long long a3,long long b3){return (a3-a1)*(b2-b1)==(a2-a1)*(b3-b1);}
bool valid(long long i,long long j,long long n,long long m){return i>=0&&i<n&&j>=0&&j<m;}
long long safe_mul_mod(long long a,long long b,const long long &mod){long long res=0,y=a%mod;while(b>0){if(b&1){res=((res%mod)+(y%mod))%mod;}y=((y%mod)*(2ll%mod))%mod;b>>=1;}return (res%mod);}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &m=INT64_MAX){if (power == 1 || power == 0)return base * power + (!power);long long res = (fast_power(base, power / 2, m) % m) % m;if (power & 1)return mul(base,mul(res,res,m),m);else return mul(res,res,m);}
long long mod_inverse_fermat(long long B,const long long&mod=1e9+7){ return fast_power(B,mod-2,mod);}//mod is prime
vector<int>mod_inverse_for_range(int p){vector<int>inv(p,1);for(int i=2;i<p;i++) {inv[i] = ( p - (p / i) * inv[p % i] % p ) % p;}return inv;}//mod is prime
vector<long long>factorial(long long n,const long long& mod){vector<long long>v(n+1,1);for(int i=2;i<=n;i++)v[i]=mul(i,v[i-1],mod);return v;}
long long NCR_MOD(long long n, long long r,vector<long long>&fact,const long long&mod){return mul(mul(fact[n], mod_inverse_fermat(fact[n - r], mod), mod), mod_inverse_fermat(fact[r], mod), mod);}
long long phi(long long n) {long long result = n;for (int i = 2; i * i <= n; i++) {if (n % i == 0) {while (n % i == 0)n /= i;result -= result / i;}}if (n > 1)result -= result / n;return result;}
vector<int>get_nth_permutation(int len,int nth){
    ordered_set<int>v;
    for(int i=0;i<len;i++)
        v.insert(i+1);
    vector<int>res;
    nth--;
    vector<int>fact= factorial(len,INT64_MAX);
    for(int i=len-1;i>=0;i--){
        int p=nth/fact[i];
        res.emplace_back(*v.find_by_order(p));
        v.erase(v.find_by_order(p));
        nth%= fact[i];
    }
    return res;
}
int permutation_in_order(vector<int>&v){
    int len=(int)v.size();
    vector<int>fact= factorial(len,INT64_MAX);
    int left=1,right=fact[len];
    while(left<=right){
        int mid=left+(right-left)/2;
        vector<int>temp= get_nth_permutation(len,mid);
        if(temp==v)return mid;
        else if(temp>v)right=mid-1;
        else left=mid+1;
    }
    return -1;
}
const int N=1e6+1;
const int mod=1e9+7;
const long long inf=3e18;
//    fast_power(base,power,m) == fast_power(base,power%phi(m),m); if gcd(base,m)==1;
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/

signed main() {
    khaled
    string str;
    cin>>str;
    int ans=0;
    int l=str.size()-1;
    int m=1<<l;
    for(int i=0;i<m;i++){
        int sum=str[0]-'0';
        for(int j=0;j<l;j++){
            if(i>>j&1){
                ans+=sum;
                sum=str[j+1]-'0';
            }else{
                sum=sum*10+str[j+1]-'0';
            }
        }
        ans+=sum;
    }
    cout<<ans<<line;
}