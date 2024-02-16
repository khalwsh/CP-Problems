#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//#include <ext/pb_ds/detail/standard_policies.hpp>//this file only make me able to use ordered set
using namespace __gnu_pbds;
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool line_checking(long long a1,long long b1,long long a2,long long b2,long long a3,long long b3){return (a3-a1)*(b2-b1)==(a2-a1)*(b3-b1);}
bool valid(long long i,long long  j,long long n,long long m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &mod=INT64_MAX){if(power==0)return 1ll;long long d= fast_power(base,power/2)%mod;d=mul(d,d,mod);if(power&1)return mul(d,base,mod);else return d;}
long long mod_inverse_fermat(long long B,const long long&mod=1e9+7){ return fast_power(B,mod-2,mod);}//mod is prime
vector<long long>mod_inverse_for_range(long long p){vector<long long>inv(p,1);for(int i=2;i<p;i++) {inv[i] = ( p - (p / i) * inv[p % i] % p ) % p;}return inv;}//mod is prime
vector<long long>factorial(long long n,const long long& mod){vector<long long>v(n+1,1);for(int i=2;i<=n;i++)v[i]=mul(i,v[i-1],mod);return v;}
int dx[]{1,-1,0,0,1,1,-1,-1};//0->4 normal,4->8 diagonal
int dy[]{0,0,1,-1,1,-1,1,-1};
#define int long long
//instead of less if write less_equal it will be considered as multiset,same as greater_equal
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// find_by_order-->get the index value, order_of_key-->how many smaller than key and with in set
const int N=1e5+5;
const int mod=1e9+7;
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
class dsu{
public:
    vector<int>parent;
    vector<int>siz;
public:
    dsu()=default;
    dsu(int n)
    {
        //intializing the parent and rank
        parent.resize(n+1);
        siz.resize(n+1,1);
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }
    int find_parent(int child)
    {
        //this function find the ultimate parent of certain child and make a update the parent
        if(parent[child]==child)
            return child;
        return parent[child]=find_parent(parent[child]);
    }
    void union_by_size(int a,int b)
    {
        int pa= find_parent(a);
        int pb= find_parent(b);
        if(pa==pb)return;
        if(siz[pa]>=siz[pb])
            siz[pa]+=siz[pb],parent[pb]=pa;
        else
            siz[pb]+=siz[pa],parent[pa]=pb;
    }
    bool same_component(int a,int b)
    {
        return find_parent(a)==find_parent(b);
    }
    bool graph_connected(int n){
        int cnt=0;
        for(int i=0;i<n;i++)
            if(i== find_parent(i))
                cnt++;
        return cnt<=1;
    }
};
signed main() {
    khaled
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>>adj[n];
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            a--,b--;
            edges.emplace_back(c, make_pair(a,b));
            adj[a].emplace_back(b,c);
            adj[b].emplace_back(a,c);
        }
        dsu d(n);
        sort(edges.begin(),edges.end());
        int c=-1;
        vector<int>min_spanning_tree;
        for(auto &val:edges){
            c++;
            if(d.find_parent(val.second.first)==d.find_parent(val.second.second))continue;
            d.union_by_size(val.second.first,val.second.second);
            min_spanning_tree.emplace_back(c);
        }
        if(!d.graph_connected(n)){
            cout<<"Case #"<<k+1<<" : "<<"No way"<<line;
        }else{
            int res=INT_MAX;
            for(auto &i:min_spanning_tree){
                dsu d2(n);
                int temp=0;
                int cnt=0;
                int cnk=-1;
                for(auto &val:edges){
                    cnk++;
                    if(i==cnk||d2.find_parent(val.second.first)==d2.find_parent(val.second.second))continue;
                    temp+=val.first;
                    cnt++;
                    d2.union_by_size(val.second.first,val.second.second);
                }
                if(cnt==n-1&&d2.graph_connected(n))
                res=min(res,temp);
            }if(res==INT_MAX){
                cout<<"Case #"<<k+1<<" : "<<"No second way"<<line;
            }else
            cout<<"Case #"<<k+1<<" : "<<res<<line;
        }
    }
}

