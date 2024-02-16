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
bool line_checking(int a1,int b1,int a2,int b2,int a3,int b3) { return (b2-b1)*(a2-a3)==(b2-b3)*(a2-a1); }
pair<int,int> rotate(int i,int j,int n){ return make_pair(j,n-1-i); }
const int N=2e5+5;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=2e17+1;
int dx[]{1,-1,0,0,1,1,-1,-1};
int dy[]{0,0,1,-1,1,-1,1,-1};
const long double pi=3.14159265350979323846,eps=1e-8;
/*==============================================  KHALWSH  ==============================================*/
struct dsu{
    vector<int>parent,size;
    int mx=0;
    void init(int n){
        parent.resize(n);
        size.resize(n,1);
        iota(parent.begin(),parent.end(),0ll);
    }
    int find(int a){
        return (a==parent[a]?a:parent[a]=find(parent[a]));
    }
    bool merge(int a,int b){
        a=find(a),b=find(b);
        if(a==b)return false;
        if(size[a]>size[b])swap(a,b);
        size[b]+=size[a];
        parent[a]=b;
        mx=max(mx,size[b]);
        return true;
    }
};
signed main() {
    khaled
    int n,d;
    cin>>n>>d;
    vector<pair<int,int>>vp;
    int temp=d;
    while(d--){
        int a,b;
        cin>>a>>b;
        a--,b--;
        vp.emplace_back(a,b);
    }
    d=temp;
    for(int i=0;i<d;i++){
        dsu du;
        du.init(n);
        int extra=0;
        for(int j=0;j<=i;j++){
            if(du.merge(vp[j].first,vp[j].second))continue;
            extra++;
        }
        if(!extra){
            cout<<du.mx-1<<line;
        }else{
            priority_queue<int>pq;
            for(int j=0;j<n;j++){
                if(j==du.parent[j]){
                    pq.push(du.size[j]);
                }
            }
            extra++;
            int res=0;
            while(extra--&&pq.size()){
                res+=pq.top();
                pq.pop();
            }
            cout<<res-1<<line;
        }
    }
}