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
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=1e18+1;
int dx[]{1,-1,0,0,1,1,-1,-1};
int dy[]{0,0,1,-1,1,-1,1,-1};
const double pi=3.14159265350979323846,eps=1e-8;
/*==============================================  KHALWSH  ==============================================*/
int n,m,k;
class SegmentTree{
public:
    int n;
    int NoOperation;
    vector<int>tree,lazy;
    void init(int _n){
        n = _n;
        NoOperation = 0;
        tree.resize(4*n);
        lazy.resize(4*n,NoOperation);
    }
    SegmentTree(int _n){
        init(_n);
    }
private:
    void build(int node,int nl,int nr,vector<int>&v){
        if(nl==nr){
            tree[node]=v[nl];
            return;
        }
        int mid = nl+(nr-nl)/2;
        build(2*node+1,nl,mid,v);
        build(2*node+2,mid+1,nr,v);
        tree[node]=max(tree[2*node+1],tree[2*node+2]);
    }
    void PropAdd(int node,int nl,int nr){
        if(lazy[node]==NoOperation)return;
        tree[node]+=lazy[node];
        if(nl!=nr){
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node]=NoOperation;
    }
    void RangeAdd(int node,int nl,int nr,int l,int r,int delta){
        PropAdd(node,nl,nr);
        if(nl>=l&&nr<=r){
            tree[node]+=delta;
            if(nl!=nr){
                lazy[2*node+1]+=delta;
                lazy[2*node+2]+=delta;
            }
            return;
        }
        if(nl>r||nr<l)return;
        int mid = nl+(nr-nl)/2;
        RangeAdd(2*node+1,nl,mid,l,r,delta);
        RangeAdd(2*node+2,mid+1,nr,l,r,delta);
        tree[node]=max(tree[2*node+1],tree[2*node+2]);
    }
    void PropAssign(int node,int nl,int nr){
        if(lazy[node]==NoOperation)return;
        tree[node]=lazy[node];
        if(nl!=nr){
            lazy[2*node+1]=lazy[node];
            lazy[2*node+2]=lazy[node];
        }
        lazy[node]=NoOperation;
    }
    void RangeAssign(int node,int nl,int nr,int l,int r,int newVal){
        PropAssign(node,nl,nr);
        if(nl>=l&&nr<=r){
            tree[node]=newVal;
            if(nl!=nr){
                lazy[2*node+1]=newVal;
                lazy[2*node+2]=newVal;
            }
            return;
        }
        if(nl>r||nr<l)return;
        int mid = nl+(nr-nl)/2;
        RangeAssign(2*node+1,nl,mid,l,r,newVal);
        RangeAssign(2*node+2,mid+1,nr,l,r,newVal);
        tree[node]=max(tree[2*node+1],tree[2*node+2]);
    }
    int QueryAdd(int node,int nl,int nr,int l,int r){
        PropAdd(node,nl,nr);
        if(nl>=l&&nr<=r){
            return tree[node];
        }
        if(nl>r||nr<l)return -inf;
        int mid = nl+(nr-nl)/2;
        return max(QueryAdd(2*node+1,nl,mid,l,r), QueryAdd(2*node+2,mid+1,nr,l,r));
    }
    int QueryAssign(int node,int nl,int nr,int l,int r){
        PropAssign(node,nl,nr);
        if(nl>=l&&nr<=r){
            return tree[node];
        }
        if(nl>r||nr<l)return -inf;
        int mid = nl+(nr-nl)/2;
        return max(QueryAssign(2*node+1,nl,mid,l,r), QueryAssign(2*node+2,mid+1,nr,l,r));
    }
public:
    void build(vector<int>&v){
        build(0,0,n-1,v);
    }
    void RangeAdd(int l,int r,int delta){
        RangeAdd(0,0,n-1,l,r,delta);
    }
    void RangeAssign(int l,int r,int newVal){
        RangeAssign(0,0,n-1,l,r,newVal);
    }
    int QueryAdd(int l,int r){
        return QueryAdd(0,0,n-1,l,r);
    }
    int QueryAssign(int l,int r){
        return QueryAssign(0,0,n-1,l,r);
    }
};

signed main() {
    khaled
    cin>>n>>m>>k;
    int res = 0;
    vector<int>v(m);
    for(auto &val:v)cin>>val;
    SegmentTree seg(m);
    seg.build(v);
    for(int i=0;i<m;){
        int temp = i,page = (seg.QueryAdd(i,i)+k-1)/k,del = 0;
        res++;
        while(i<m&&(seg.QueryAdd(temp,i)+k-1)/k == page)
            i++,del++;
        seg.RangeAdd(i,n-1,-del);
    }
    cout<<res<<line;
}