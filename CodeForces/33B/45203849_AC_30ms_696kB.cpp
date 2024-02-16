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
int dx[]{1,-1,0,0,1,1,-1,-1};//0->4 normal,4->8 diagonal
int dy[]{0,0,1,-1,1,-1,1,-1};
const long double pi=3.14159265350979323846;
const long double Eps=1e-10;
#define int long long
template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N=1e7+1;
const int mod=1e9+7;
const long long inf=1e17;
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
signed main() {
    khaled
    string a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    if(a.size()!=b.size()){
        cout<<-1<<line;
        return 0;
    }
    vector<vector<int>> adj(26, vector<int>(26, inf));
    for (int i = 0; i < 26; i++)adj[i][i] = 0;
    for (int i = 0; i < n; i++) {
        char from, to;
        int cost;
        cin >> from >> to >> cost;
        adj[from - 'a'][to - 'a'] = min(adj[from - 'a'][to - 'a'], cost);
    }
    for (int k = 0; k < 26; k++) {
        //via
        for (int i = 0; i < 26; i++) {
            //from
            for (int j = 0; j < 26; j++) {
                //to
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    bool negative_cycle = false;
    for (int i = 0; i < 26; i++)negative_cycle = negative_cycle || (adj[i][i] < 0);
    if (negative_cycle) {
        cout << -1;
        return 0;
    }
    vector<vector<pair<int,char>>>minmize(26,vector<pair<int,char>>(26));
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            minmize[i][j]= make_pair(adj[i][j],(char)(j+'a'));
        }
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            for(int k=0;k<26;k++){
                if(adj[i][k]+adj[j][k]<minmize[i][j].first){
                    minmize[i][j]= make_pair(adj[i][k]+adj[j][k],(char)(k+'a'));
                }
            }
        }
    }

    bool fail = false;
    int res = 0;
    string final_res;
    for (int i = 0; i < a.size(); i++) {
        if (minmize[a[i] - 'a'][b[i] - 'a'].first == inf && minmize[b[i] - 'a'][a[i] - 'a'].first == inf) {
            fail = true;
            break;
        }
        if (minmize[a[i] - 'a'][b[i] - 'a'].first < minmize[b[i] - 'a'][a[i] - 'a'].first)
            res += minmize[a[i] - 'a'][b[i] - 'a'].first, final_res += minmize[a[i]-'a'][b[i]-'a'].second;
        else
            res += minmize[b[i] - 'a'][a[i] - 'a'].first, final_res += minmize[b[i]-'a'][a[i]-'a'].second;
    }
    if(fail)cout<<-1;
    else cout << res << line << final_res << line;
}