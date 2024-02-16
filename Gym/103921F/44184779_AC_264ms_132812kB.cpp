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
typedef tree<int, null_type, greater_equal<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// find_by_order-->get the index value, order_of_key-->how many smaller than key and with in set
const int N=1e5+5;
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
        else if(siz[pb]>siz[pa])
            siz[pb]+=siz[pa],parent[pa]=pb;
    }
    bool same_component(int a,int b)
    {
        return find_parent(a)==find_parent(b);
    }
};
signed main() {
    khaled
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &val:v)cin>>val;
    vector<pair<int,int>>adj1[n],adj2[n];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            adj1[i].emplace_back(j,v[i]&v[j]);
            adj1[j].emplace_back(i,v[i]&v[j]);
            bitset<32>b1(v[i]),b2(v[j]);
            for(int k=0;k<32;k++)
                b1[k]=!b1[k],b2[k]=!b2[k];
            int cal=b1.to_ullong()&b2.to_ullong();
            adj2[i].emplace_back(j,cal);
            adj2[j].emplace_back(i,cal);
        }
    }
    vector<int>dist(n,(int)1e16);
    dist[0]=0;
    priority_queue<pair<int,pair<int,bool>>,vector<pair<int,pair<int,bool>>>,greater<>>pq;
    pq.push({0, {0,1}});
    pq.push({0,{0,0}});
    while(!pq.empty()){
        int node=pq.top().second.first;
        bool graph=pq.top().second.second;
        int cost=pq.top().first;
        pq.pop();
        if(cost!=dist[node])continue;
        if(graph==0){
            for(auto &val:adj1[node]){
                if(dist[val.first]>cost+val.second)
                    dist[val.first]=cost+val.second,pq.push({dist[val.first],{val.first,0}}),pq.push({dist[val.first],{val.first,1}});
            }
        }else{
            for(auto &val:adj2[node]){
                if(dist[val.first]>cost+val.second)
                    dist[val.first]=cost+val.second,pq.push({dist[val.first],{val.first,0}}),pq.push({dist[val.first],{val.first,1}});
            }
        }
    }
    cout<<dist[n-1];
}
