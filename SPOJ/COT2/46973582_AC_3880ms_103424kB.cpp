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
const int N=8e5+1;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=2e17+1;
/*=======================================================================================================*/
/*==============================================  KHALWSH  ==============================================*/
/*=======================================================================================================*/
struct Query;

const int k=21,SQ=317;

int timer=0,n,res=0,MoLeft=0,MoRight=-1;

int Weight[N],Parent[N],BinaryLifting[k][N],Depth[N],LinearTree[N],StartTime[N],EndingTime[N],freq[N],ans[N],compress[N];

vector<Query>queries;

bool state[N];

vector<int>adj[N];

void rooting(int node,int par){
    queue<pair<int,int>>q;
    q.push({node,par});
    while(!q.empty()){
        node=q.front().first;
        par=q.front().second;
        q.pop();
        for(auto &val:adj[node]){
            if(val==par)continue;
            Parent[val]=node;
            q.push({val,node});
        }
    }
}

void BuildLiftingTable(){
    for(int i=0;i<n;i++)BinaryLifting[0][i]=Parent[i];
    for(int i=1;i<k;i++){
        for(int j=0;j<n;j++){
            BinaryLifting[i][j]=BinaryLifting[i-1][BinaryLifting[i-1][j]];
        }
    }
}

void MarkDepth(int node,int par,int dist){
    Depth[node]=dist;
    for(auto &val:adj[node]){
        if(val==par)continue;
        MarkDepth(val,node,dist+1);
    }
}

int WalkThroughEdges(int a,int kth){
    if(Depth[a]<kth)return 0;
    for(int i=0;i<k;i++){
        if(kth&(1<<i))a=BinaryLifting[i][a];
    }
    return a;
}

int LCA(int a,int b){
    if(Depth[b]>Depth[a])swap(b,a);
    a= WalkThroughEdges(a,Depth[a]-Depth[b]);
    if(a==b)return a;
    for(int i=k-1;i>=0;i--){
        if(BinaryLifting[i][a]!=BinaryLifting[i][b]){
            a=BinaryLifting[i][a];
            b=BinaryLifting[i][b];
        }
    }
    assert(BinaryLifting[0][a]==BinaryLifting[0][b]&&BinaryLifting[0][a]==Parent[a]);
    return BinaryLifting[0][a];
}

void Linearization(int node,int par){
    LinearTree[timer]=node;
    StartTime[node]=timer++;
    for(auto &val:adj[node]){
        if(val==par)continue;
        Linearization(val,node);
    }
    LinearTree[timer]=node;
    EndingTime[node]=timer;
    timer++;
}

struct Query{
    int l,r,idx,lca;
    bool i;
    Query(int a,int b,int c,int x,bool flag=false){
        l=a;
        r=b;
        idx=c;
        lca=x;
        i=flag;
    }
    bool operator<(const Query& a){
        return make_pair(l/SQ,r)< make_pair(a.l/SQ,a.r);
    }
};

void AddElement(int node){
    freq[compress[node]]++;
    if(freq[compress[node]]==1)res++;
}

void EraseElement(int node){
    freq[compress[node]]--;
    if(freq[compress[node]]==0)res--;
}

void UpdateMoState(int node){
    state[node]^=true;
    return void(state[node]? AddElement(node): EraseElement(node));
}

void Mo(int l,int r){
    while(MoLeft>l){
        MoLeft--;
        UpdateMoState(LinearTree[MoLeft]);
    }
    while(MoLeft<l){
        UpdateMoState(LinearTree[MoLeft]);
        MoLeft++;
    }
    while(MoRight<r){
        MoRight++;
        UpdateMoState(LinearTree[MoRight]);
    }
    while(MoRight>r){
        UpdateMoState(LinearTree[MoRight]);
        MoRight--;
    }
}

void RunSolution(){
    int q;
    cin>>n>>q;

    for(int i=0;i<n;i++)cin>>Weight[i];
    int p=0;
    map<int,vector<int>>mp;
    for(int i=0;i<n;i++)mp[Weight[i]].emplace_back(i);
    for(auto &val:mp){
        for(auto &i:val.second)
            compress[i]=p;
        p++;
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    rooting(0,-1);

    BuildLiftingTable();

    MarkDepth(0,-1,0);

    Linearization(0,-1);

    int cnt=0;

    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        l--,r--;
        if(StartTime[l]>StartTime[r])swap(l,r);
        int lca= LCA(l,r);
        if(lca==l){
            queries.emplace_back(StartTime[lca],StartTime[r],cnt,lca,1);
        }
        else{
            queries.emplace_back(EndingTime[l],StartTime[r],cnt,lca);
        }
        cnt++;
    }

    sort(queries.begin(),queries.end());

    for(auto &val:queries){
        Mo(val.l,val.r);
        if(!val.i)
           UpdateMoState(val.lca);
        ans[val.idx]=res;
        if(!val.i)
           UpdateMoState(val.lca);
    }

    for(int i=0;i<q;i++){
        cout<<ans[i]<<line;
    }

}

signed main() {
    khaled
    RunSolution();
}