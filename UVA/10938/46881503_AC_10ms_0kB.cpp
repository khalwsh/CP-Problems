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
const int N=5e3+1;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=2e17+1;
/*=======================================================================================================*/
/*==============================================  KHALWSH  ==============================================*/
/*=======================================================================================================*/
vector<int>adj[N];
int parent[N],Depth[N];
const int k=20;
int BinaryLifting[k][N];
void init(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++)BinaryLifting[j][i]=0;
        parent[i]=0;
        Depth[i]=0;
        adj[i].clear();
    }
}
void MarkDepth(int node,int par,int l=0){
    Depth[node]=l;
    for(auto &val:adj[node]){
        if(val!=par)MarkDepth(val,node,l+1);
    }
}
int Walk(int a,int kth){
    if(Depth[a]<kth)return -1;
    for(int i=0;i<k;i++){
        if(kth&(1<<i))a=BinaryLifting[i][a];
    }
    return a;
}
int LCA(int a,int b){
    if(Depth[b]>Depth[a])swap(a,b);
    a= Walk(a,Depth[a]-Depth[b]);
    if(a==b)return a;
    for(int i=k-1;i>=0;i--){
        if(BinaryLifting[i][a]!=BinaryLifting[i][b]){
            b=BinaryLifting[i][b];
            a=BinaryLifting[i][a];
        }
    }
    return BinaryLifting[0][a];
}
int dist(int a,int b){
    return Depth[a]+Depth[b]-2*Depth[LCA(a,b)];
}
void build(int n){
    for(int i=0;i<n;i++){
        BinaryLifting[0][i]=parent[i];
    }
    for(int i=1;i<k;i++){
        for(int j=0;j<n;j++){
            BinaryLifting[i][j]=BinaryLifting[i-1][BinaryLifting[i-1][j]];
        }
    }
}
void rooting(){
    queue<pair<int,int>>q;
    q.emplace(0,-1);
    while(!q.empty()){
        int node=q.front().first;
        int par=q.front().second;
        q.pop();
        for(auto &val:adj[node]){
            if(val==par)continue;
            parent[val]=node;
            q.emplace(val,node);
        }
    }
}
signed main() {
    khaled
    while(true){
        int n;cin>>n;if(!n)break;
        init(n);
        for(int i=0;i<n-1;i++){
            int a,b;
            cin>>a>>b;a--,b--;
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }
        rooting();
        MarkDepth(0,-1,0);
        build(n);
        int q;
        cin>>q;
        while(q--){
            int a,b;
            cin>>a>>b;
            a--,b--;
            int d=dist(a,b);
            if(d&1){
                int i,j;
                if(Depth[b]>=Depth[LCA(a,b)]+d/2+1){
                    i= Walk(b,d/2);
                    j= Walk(i,1);
                }else{
                    i= Walk(a,d/2);
                    j= Walk(i,1);
                }
                if(i>j)swap(i,j);
                i++,++j;
                cout<<"The fleas jump forever between "<<i<<" and "<<j<<"."<<line;
            }else {
                int i;
                if(Depth[b]>=Depth[LCA(a,b)]+d/2){
                    i= Walk(b,d/2);
                }else{
                    i= Walk(a,d/2);
                }
                cout << "The fleas meet at " << i+1 << "." << line;
            }
        }
    }
}