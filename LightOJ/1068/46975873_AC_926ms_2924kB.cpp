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
const int N=8e5+1;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=2e17+1;
/*=======================================================================================================*/
/*==============================================  KHALWSH  ==============================================*/
/*=======================================================================================================*/
vector<int>powers;
int dp[11][91][91][2][2];
int vis[11][91][91][2][2];
int tx=1;
int solve(int index,string &a,string&b,int DigitSum,int rem,bool down,bool up,int k){
    if(index==a.size()){
        return !rem&&!DigitSum;
    }
    int &ret=dp[index][DigitSum][rem][down][up];
    if(vis[index][DigitSum][rem][down][up]==tx)return ret;
    vis[index][DigitSum][rem][down][up]=tx;
    int res=0;
    int lim=(up?9:b[index]-'0');
    int start=(down?0:a[index]-'0');
    for(int i=start;i<=lim;i++){
        res+=solve(index+1,a,b,add(DigitSum,i,k),add(rem,mul(i,powers[index],k),k),down||i>a[index]-'0',up||i<b[index]-'0',k);
    }
    return ret = res;
}
signed main() {
    khaled
    int t;
    cin>>t;
    int cnt=1;
    while(t--){
        int l,r,k;
        cin>>l>>r>>k;
        cout<<"Case "<<cnt++<<": ";
        if(k>=90){
            cout<<0<<line;
        }else{
            string a,b;
            a= to_string(l);
            b= to_string(r);
            while(a.size()<b.size())a='0'+a;
            powers.resize(a.size());
            powers[0]=1;
            for(int i=1;i<powers.size();i++)powers[i]=mul(powers[i-1],10ll,k);
            reverse(powers.begin(),powers.end());
            cout<<solve(0,a,b,0,0,false,false,k)<<line;
            powers.clear();
        }
        tx++;
    }
}