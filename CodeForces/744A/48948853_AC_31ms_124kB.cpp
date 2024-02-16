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
int SafeMul(int a,int b,int m){if(b==0)return 0;int res = SafeMul(a,b/2,m);res = add(res,res,m);if(b&1)return add(res,a,m);else return res;}
long long fast_power(long long base,long long power,const long long &m=INT64_MAX){if (power == 1 || power == 0)return base * power + (!power);long long res = (fast_power(base, power / 2, m) % m) % m;if (power & 1)return mul(base,mul(res,res,m),m);else return mul(res,res,m);}
int log2_floor(long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : 0;}
int power_of_2(int n){ return __builtin_popcountll(n)==1;}
bool line_checking(int a1,int b1,int a2,int b2,int a3,int b3) { return (b2-b1)*(a2-a3)==(b2-b3)*(a2-a1); }
pair<int,int> rotate(int i,int j,int n){ return make_pair(j,n-1-i); }
const int N = 5e5+5;
//const int mod=1e9+7;
const int mod = 998244353;
const long long inf=1e9+1;
int dx[]{1,-1,0,0,1,1,-1,-1};
int dy[]{0,0,1,-1,1,-1,1,-1};
const double pi=3.14159265350979323846,eps=1e-8;
/*==============================================  KHALWSH  ==============================================*/
struct dsu{
    int n,cnt;
    vector<int>size,parent,nxt,tail,sets,pos;
    void init(int nn){
        this->n=nn;
        size.resize(n,1);
        parent.resize(n);
        nxt.resize(n,-1);
        sets.resize(n);
        pos.resize(n);
        tail.resize(n);
        iota(parent.begin(),parent.end(),0);
        iota(tail.begin(),tail.end(),0);
        iota(sets.begin(),sets.end(),0);
        iota(pos.begin(),pos.end(),0);
        cnt=nn;
    }
    dsu (int n=0){
        init(n);
    }
    int find(int child){
        return (child==parent[child]?child:parent[child]=find(parent[child]));
    }
    bool merge(int u,int v){
        u=find(u);
        v=find(v);
        if(v==u)return false;
        if(size[u]<size[v])swap(u,v);
        parent[v]=u;
        size[u]+=size[v];
        int p=pos[v];
        pos[sets[p]=sets[--cnt]]=p;
        int &t=tail[u];
        nxt[t]=v;
        t=tail[v];
        return true;

    }
    vector<int>get_set(int node){
        node=find(node);
        vector<int>res;
        for(int i=sets[node];~i;i=nxt[i]){
            res.emplace_back(i);
        }
        return  res;
    }
};
signed main() {
    khaled
    int n,m,k;
    cin>>n>>m>>k;
    dsu d (n);
    vector<int>temp(k);
    for(auto &val:temp)cin>>val,val--;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        d.merge(a,b);
    }
    set<int>cap(temp.begin(),temp.end());
    int res = 0;
    vector<int>leaders;
    for(int i=0;i<n;i++){
        if(i==d.parent[i])leaders.emplace_back(i);
    }
    vector<int>siz;
    int mx = 0;
    for(auto &val:leaders){
        vector<int>g = d.get_set(val);
        res += (int)g.size()*((int)g.size()-1)/2;
        bool fail = false;
        for(auto &i:g){
            if(cap.count(i)){
                fail = true;break;
            }
        }
        if(!fail){
            siz.emplace_back(g.size());
        }else{
            mx = max(mx,(int)g.size());
        }
    }
    for(int i=0;i<siz.size();i++){
        res+=mx*siz[i];
        for(int j=i+1;j<siz.size();j++){
            res+=(siz[i]*siz[j]);
        }
    }
    cout<<res-m<<line;

}