//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
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
const int N=5e5+1;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=9e18+1;
//__builtin_clzll(x): the number of zeros at the beginning of the number
//__builtin_ctzll(x): the number of zeros at the end of the number
//__builtin_popcountll(x): the number of ones in the number
//__builtin_parityll(x): the parity (even or odd) of the number of ones
/*=======================================================================================================*/
/*==============================================  KHALWSH  ==============================================*/
/*=======================================================================================================*/


signed main() {
    khaled
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<pair<int,pair<int,int>>>pairs;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            a--,b--;
            pairs.emplace_back(a, make_pair(b,i));
        }
        vector<int>res(n);
        sort(pairs.begin(),pairs.end());
        int mx=pairs[0].second.first;

        res[pairs[0].second.second]=1;
        bool work=false;
        for(int i=1;i<n;i++){
            if(pairs[i].first>mx){
                for(int j=i;j<n;j++)res[pairs[j].second.second]=2;
                work=true;
                break;
            }else {
                res[pairs[i].second.second] = 1;
            }
            mx=max(mx,pairs[i].second.first);
        }
        if(!work){
            cout<<-1<<line;
            continue;
        }
        for(auto &val:res)
            cout<<val<<" ";
        cout<<line;
    }
}
