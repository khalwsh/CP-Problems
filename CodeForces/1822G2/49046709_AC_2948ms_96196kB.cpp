#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int long long
#define double long double
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
bool valid(long long i,long long j,long long n,long long m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
int SafeMul(int a,int b,int m){if(b==0)return 0;int res = SafeMul(a,b/2,m);res = add(res,res,m);if(b&1)return add(res,a,m);else return res;}
long long fast_power(long long base,long long power,const long long &m=INT64_MAX){if (power == 1 || power == 0)return base * power + (!power);long long res = (fast_power(base, power / 2, m) % m) % m;if (power & 1)return mul(base,mul(res,res,m),m);else return mul(res,res,m);}
int log2_floor(long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : 0;}
int power_of_2(int n){ return __builtin_popcountll(n)==1;}
bool line_checking(int a1,int b1,int a2,int b2,int a3,int b3) { return (b2-b1)*(a2-a3)==(b2-b3)*(a2-a1); }
pair<int,int> rotate(int i,int j,int n){ return make_pair(j,n-1-i); }
const int N =1e6+5;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=1e18+1;
int dx[]{2,2,-2,-2,1,-1,1,-1};
int dy[]{1,-1,1,-1,2,2,-2,-2};
const double pi=3.14159265350979323846,eps=1e-8;
/*==============================================  KHALWSH  ==============================================*/
int cal(int f){
    return f*(f-1)*(f-2);
}
void G2(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;vector<int>v(n);
        for(auto &val:v)cin>>val;
        map<int,int>freq;
        for(auto &val:v)freq[val]++;
        sort(v.begin(),v.end());
        int res = cal(freq[v[0]]);
        for(int i=1;i<n;i++){
            if(v[i]==v[i-1])continue;
            res+=cal(freq[v[i]]);
        }
        for(int i=0;i<n;i++){
            set<int>divs;
            if(i&&v[i]==v[i-1])continue;
            for(int j = 1;j*j*j<=v[i];j++){
                if(v[i]%j!=0)continue;
                if(j!=1&&v[i]/j%j==0)divs.insert(j);
                int other = (int)sqrt(v[i]/j);
                if(other*other != v[i]/j)continue;
                if(other!=1)divs.insert(other);
            }
            for(auto &val:divs){
                if(val==1)continue;
                res+=freq[v[i]]*freq[v[i]/val]*freq[v[i]/val/val];
            }
        }
        cout<<res<<line;
    }
}
signed main() {
    khaled
    G2();
}