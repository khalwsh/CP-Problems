#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
int dx[]{1,-1,0,0,1,1,-1,-1};//0->4 normal,4->8 diagonal
int dy[]{0,0,1,-1,1,-1,1,-1};
const long double pi=3.14159265350979323846;
const long double Eps=1e-10;
#define int long long
template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N=1e2+1;
const int mod=1e9+7;
const long long inf=3e18;
//remember ya 3l2 enter this gym on your free time :The 2022 SDUT Summer Trials
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
signed main() {
    khaled
    int t;
    cin>>t;
    while(t--) {
        int k, n, m;
        cin >> k >> n >> m;
        int temp = k;
        int pointer1 = 0, pointer2 = 0;
        vector<int> a, b, res;
        a.resize(n);
        b.resize(m);
        for (auto &val: a)cin >> val;
        for (auto &val: b)cin >> val;
        bool fail = false;
        while (pointer1 < n && pointer2 < m) {
            if (a[pointer1] == 0)pointer1++, k++, res.emplace_back(0);
            else if (b[pointer2] == 0)pointer2++, k++, res.emplace_back(0);
            else {
                if (a[pointer1] < b[pointer2]) {
                    if (a[pointer1] > k)fail = true;
                    else {
                        res.emplace_back(a[pointer1]);
                        pointer1++;
                    }
                } else {
                    if (b[pointer2] > k)fail = true;
                    else {
                        res.emplace_back(b[pointer2]);
                        pointer2++;
                    }
                }
            }
            if (fail)break;
        }
        while(pointer1<n){
            if (a[pointer1] == 0)pointer1++, k++, res.emplace_back(0);
            else {
                if (a[pointer1] > k)fail = true;
                else {
                    res.emplace_back(a[pointer1]);
                    pointer1++;
                }
            }
            if (fail)break;
        }
        while(pointer2<m){
            if (b[pointer2] == 0)pointer2++, k++, res.emplace_back(0);
            else {
                if (b[pointer2] > k)fail = true;
                else {
                    res.emplace_back(b[pointer2]);
                    pointer2++;
                }
            }
            if (fail)break;
        }
        if (fail) {
            cout << -1;
            cout<<line;
        } else {
            for (auto &val: res)cout << val << " ";
            cout << line;
        }
    }
}