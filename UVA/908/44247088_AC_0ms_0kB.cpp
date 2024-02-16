#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//#include <ext/pb_ds/detail/standard_policies.hpp>//this file only make me able to use ordered set
using namespace __gnu_pbds;
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool line_checking(long long a1,long long b1,long long a2,long long b2,long long a3,long long b3){return (a3-a1)*(b2-b1)==(a2-a1)*(b3-b1);}
bool valid(int i,int j,int n,int m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &mod=INT64_MAX){if(power==0)return 1ll;long long d= fast_power(base,power/2)%mod;d=mul(d,d,mod);if(power&1)return mul(d,base,mod);else return d;}
long long mod_inverse_fermat(long long B,const long long&mod=1e9+7){ return fast_power(B,mod-2,mod);}//mod is prime
vector<int>mod_inverse_for_range(int p){vector<int>inv(p,1);for(int i=2;i<p;i++) {inv[i] = ( p - (p / i) * inv[p % i] % p ) % p;}return inv;}//mod is prime
vector<long long>factorial(long long n,const long long& mod){vector<long long>v(n+1,1);for(int i=2;i<=n;i++)v[i]=mul(i,v[i-1],mod);return v;}
int dx[]{1,-1,0,0,1,1,-1,-1};//0->4 normal,4->8 diagonal
int dy[]{0,0,1,-1,1,-1,1,-1};
#define int long long
//instead of less if write less_equal it will be considered as multiset,same as greater_equal
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// find_by_order-->get the index value, order_of_key-->how many smaller than key and with in set
const int N=1e5+5;
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
class dsu{
public:
    vector<int>parent,siz;
    dsu(int n){
        parent.resize(n);
        siz.resize(n,1);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int find_parent(int child){
        return (child==parent[child]?child:parent[child]=find_parent(parent[child]));
    }
    void union_by_size(int a,int b){
        a= find_parent(a);
        b= find_parent(b);
        if(a==b)return ;
        if(siz[a]>siz[b])
            siz[a]+=siz[b],parent[b]=a;
        else
            siz[b]+=siz[a],parent[a]=b;
    }
    bool connected(int n){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i)
                cnt++;
        }
        return cnt<=1;
    }
};
long long min_spanning_tree(vector<pair<int,pair<int,int>>>&edges,int n){
    sort(edges.begin(),edges.end());
    dsu d(n);
    int res=0;
    for(auto &val:edges){
        if(d.find_parent(val.second.first)==d.find_parent(val.second.second))continue;
        d.union_by_size(val.second.first,val.second.second);
        res+=val.first;
    }
    return res;
}
signed main() {
    khaled
    int n;
    int t=0;
    while(cin>>n){
       vector<pair<int,pair<int,int>>>edges1,edges2;
       for(int i=0;i<n-1;i++){
           int a,b,c;
           cin>>a>>b>>c;
           a--,b--;
           edges1.emplace_back(c, make_pair(a,b));
           edges2.emplace_back(c, make_pair(a,b));
       }
       if(t)
           cout<<line;
       t++;
       int k;
       cin>>k;
       while(k--){
           int a,b,c;
           cin>>a>>b>>c;
           a--,b--;
           edges2.emplace_back(c, make_pair(a,b));
       }
       int m;
       cin>>m;
       while(m--){
           int a,b,c;
           cin>>a>>b>>c;
           a--,b--;
           edges1.emplace_back(c, make_pair(a,b));
           edges2.emplace_back(c, make_pair(a,b));
       }
       cout<<min_spanning_tree(edges1,n)<<line<<min_spanning_tree(edges2,n)<<line;
    }
}