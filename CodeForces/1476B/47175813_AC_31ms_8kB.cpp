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
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        for(auto &val:v)cin>>val;
        vector<int>pre(v);
        for(int i=1;i<n;i++)pre[i]+=pre[i-1];
        int delta=0;
        for(int i=1;i<n;i++){
            if((pre[i-1]+delta)*k>=v[i]*100ll){
                continue;
            }else{
                int left=1,right=1e12;
                int temp=0;
                while(left<=right){
                    int mid=left+(right-left)/2;
                    if((pre[i-1]+delta+mid)*k>=v[i]*100ll){
                        temp=mid;
                        right=mid-1;
                    }else
                        left=mid+1;
                }
                delta+=temp;
            }
        }
        cout<<delta<<line;
    }
}