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
bool line_checking(long long a1,long long b1,long long a2,long long b2,long long a3,long long b3) {return (a3 - a1) * (b2 - b1) == (a2 - a1) * (b3 - b1);}
const int N=2e5+1;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=2e17+1;
/*=======================================================================================================*/
/*==============================================  KHALWSH  ==============================================*/
/*=======================================================================================================*/
const int k=25;
int sp[k+1][N];
void build(int n){
    for(int i=1;i<=k;i++){
        for(int j=0;j+(1<<i)<=n;j++){
            sp[i][j]=min(sp[i-1][j],sp[i-1][j+(1<<(i-1))]);
        }
    }
}
int query(int l,int r){
    int lg= log2_floor(r-l+1);
    return min(sp[lg][l],sp[lg][r-(1<<lg)+1]);
}
signed main() {
    khaled
    int n;
    string s;
    cin>>n>>s;
    int left=0,right=(int)s.size()-1;
    for(int i=0;i<n;i++){
        sp[0][i]=s[i]-'a';
    }
    build(n);
    while(left<right){
        if(query(left,right)==s[left]-'a'){
            left++;continue;
        }
        int q= query(left,right);
        while(s[right]-'a'!=q){
            right--;
        }
        swap(s[right],s[left]);
        left++,right--;
    }
    cout<<s<<line;
}
