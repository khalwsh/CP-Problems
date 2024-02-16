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
long long fast_power(long long base,long long power,const long long &m=INT64_MAX){if (power == 1 || power == 0)return base * power + (!power);long long res = (fast_power(base, power / 2, m) % m) % m;if (power & 1)return mul(base,mul(res,res,m),m);else return mul(res,res,m);}
int log2_floor(long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : 0;}
int power_of_2(int n){ return __builtin_popcountll(n)==1;}
bool line_checking(int a1,int b1,int a2,int b2,int a3,int b3) { return (b2-b1)*(a2-a3)==(b2-b3)*(a2-a1); }
pair<int,int> rotate(int i,int j,int n){ return make_pair(j,n-1-i); }
const int N=1e5+5;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=8e18+1;
int dx[]{1,-1,0,0,1,1,-1,-1};
int dy[]{0,0,1,-1,1,-1,1,-1};
const double pi=3.14159265350979323846,eps=1e-8;
/*==============================================  KHALWSH  ==============================================*/
const int k =21;
int Mx[k][N],Mn[k][N];
int queryMn(int l,int r){
    int lg = log2_floor(r-l+1);
    return min(Mn[lg][l],Mn[lg][r-(1<<lg)+1]);
}
int queryMx(int l,int r){
    int lg = log2_floor(r-l+1);
    return max(Mx[lg][l],Mx[lg][r-(1<<lg)+1]);
}
signed main() {
    khaled
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>rev=v;
    reverse(rev.begin(),rev.end());
    if(is_sorted(v.begin(),v.end())|| is_sorted(rev.begin(),rev.end())){
        cout<<0<<line;
        exit(0);
    }
    std::copy(v.begin(),v.end(),Mx[0]);
    std::copy(v.begin(),v.end(),Mn[0]);
    for(int i=1;i<k;i++){
        for(int j=0;j+(1<<i)<=n;j++){
            Mx[i][j]=max(Mx[i-1][j],Mx[i-1][j+(1<<(i-1))]);
            Mn[i][j]=min(Mn[i-1][j],Mn[i-1][j+(1<<(i-1))]);
        }
    }
    for(int i=1;i<n-1;i++){
        if(v[i]> queryMn(0,i-1)&&v[i]> queryMn(i+1,n-1)){
            cout<<3<<line;
            for(int j=0;j<i;j++){
                if(queryMn(0,i-1)==v[j]){
                    cout<<j+1<<" ";
                    break;
                }
            }
            cout<<i+1<<" ";
            for(int j=i+1;j<n;j++){
                if(queryMn(i+1,n-1)==v[j]){
                    cout<<j+1<<" ";
                    break;
                }
            }
            exit(0);
        }else if(v[i]< queryMx(0,i-1)&&v[i]< queryMx(i+1,n-1)){
            cout<<3<<line;
            for(int j=0;j<i;j++){
                if(queryMx(0,i-1)==v[j]){
                    cout<<j+1<<" ";
                    break;
                }
            }
            cout<<i+1<<" ";
            for(int j=i+1;j<n;j++){
                if(queryMx(i+1,n-1)==v[j]){
                    cout<<j+1<<" ";
                    break;
                }
            }
            exit(0);
        }
    }
    cout<<0<<line;
}