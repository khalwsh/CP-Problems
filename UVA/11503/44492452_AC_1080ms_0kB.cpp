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
//count how many permutation of length n that ith index not equal to i//should apply dp to this function
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
template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N=2e5+2;
const int mod=1e9+7;
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
class dsu{
public:
    map<string,string>parent;map<string,int>siz;
    string find_parent(string&child){
        return (child==parent[child]?child:parent[child]= find_parent(parent[child]));
    }
    void exist(string &s){
        if(parent.count(s)==0)parent[s]=s,siz[s]=1;
    }
    void union_by_siz(string&s1,string&s2){
        s1= find_parent(s1);
        s2= find_parent(s2);
        if(s1==s2)return;
        if(siz[s1]<siz[s2])swap(s1,s2);
        siz[s1]+=siz[s2];
        parent[s2]=s1;
    }
};
signed main() {
    khaled
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;dsu d;
        while(n--){
            string s1,s2;
            cin>>s1>>s2;
            d.exist(s1);d.exist(s2);
            d.union_by_siz(s1,s2);
            cout<<d.siz[d.find_parent(s1)]<<line;
        }
    }
}