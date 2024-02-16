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
const int N=1e6+1;
//const int mod=1e9+7;
const int mod = 998244353;
const long long inf=2e17;
//__builtin_clzll(x): the number of zeros at the beginning of the number
//__builtin_ctzll(x): the number of zeros at the end of the number
//__builtin_popcountll(x): the number of ones in the number
//__builtin_parityll(x): the parity (even or odd) of the number of ones
/*=======================================================================================================*/
/*==============================================  KHALWSH  ==============================================*/
/*=======================================================================================================*/
int k=26;
void build(int n,vector<vector<int>>&sp){
    for(int i=1;i<=k;i++){
        for(int j=0;j+(1<<i)<=n;j++){
            sp[i][j]=min(sp[i-1][j],sp[i-1][j+(1<<(i-1))]);
        }
    }
}
int query(int l,int r,vector<vector<int>>&sp){
    int lg= log2_floor(r-l+1);
    return min(sp[lg][l],sp[lg][r-(1<<lg)+1]);
}
void Queue(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &val:v)cin>>val;
    vector<int>ans(n);
    vector<vector<int>>sparse(k+1,vector<int>(n));
    std::copy(v.begin(),v.end(),sparse[0].begin());
    build(n,sparse);
    for(int i=0;i<n;i++){
        int left=i;
        int right=n-1;
        if(query(left,right,sparse)>=v[i])ans[i]=-1;
        else {
            int res=-1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (query(mid,n-1,sparse)<v[i]){
                    res=mid;
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
            ans[i]=res-i-1;
        }
    }
    for(auto &val:ans)cout<<val<<" ";
    cout<<line;
}
signed main() {
    khaled
    Queue();
}