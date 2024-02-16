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
bool line_checking(int a1,int a2,int a3,int b1,int b2,int b3) {return (a3 - a1) * (b2 - b1) == (a2 - a1) * (b3 - b1);}
pair<int,int> rotate(int i,int j,int n){ return make_pair(j,n-1-i); }
const int N=2e5+5;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=2e17+1;
int dx[]{1,-1,0,0,1,1,-1,-1};
int dy[]{0,0,1,-1,1,-1,1,-1};
const long double pi=3.14159265350979323846,eps=1e-9;
/*==============================================  KHALWSH  ==============================================*/

signed main(){
    khaled
    string s;
    cin>>s;
    if(s.size()<4){
        cout<<"-1";
        exit(0);
    }
    int f=-1,l=-1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='['){
            f=i;
            break;
        }
    }
    for(int j=(int)s.size()-1;j>=0;j--){
        if(s[j]==']'){
            l=j;
            break;
        }
    }
    if(f==-1||l==-1||f>l){
        cout<<-1<<line;
        exit(0);
    }
    int a=-1,b=-1;
    for(int i=f+1;i<l;i++){
        if(s[i]==':'){
            a=i;
            break;
        }
    }
    for(int j=l-1;j>f;j--){
        if(s[j]==':'){
            b=j;
            break;
        }
    }
    if(a==-1||b==-1||a==b){
        cout<<-1<<line;
        exit(0);
    }
    int res=4;
    for(int i=a+1;i<b;i++){
        if(s[i]=='|')res++;
    }
    cout<<res<<line;
}