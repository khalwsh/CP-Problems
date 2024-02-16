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
const int N=1e6+1;
//const int mod=1e9+7;
const int mod = 998244353;
const long long inf=2e17;
//__builtin_clzll(x): the number of zeros at the beginning of the number
//__builtin_ctzll(x): the number of zeros at the end of the number
//__builtin_popcountll(x): the number of ones in the number
//__builtin_parityll(x): the parity (even or odd) of the number of ones
/*=======================================================================================================*/
/*==============================================  KHALWSH  ==============================================*/
/*=======================================================================================================*/
class SegmentTree{
public:
    vector<int>tree,lazy;
    int n;
    SegmentTree(int n){
        this->n=n;
        tree.resize(n*4);
        lazy.resize(n*4);
    }
    void update(int node,int nl,int nr,int l,int r){
        if(lazy[node]!=0){
            tree[node]=(lazy[node]&1?(nr-nl+1-tree[node]):tree[node]);
            if(nl!=nr&&lazy[node]&1){
                lazy[2*node+1]+=lazy[node];
                lazy[2*node+2]+=lazy[node];
            }
            lazy[node]=0;
        }
        if(nr<l||nl>r)return ;
        if(nl>=l&&nr<=r){
            tree[node]=nr-nl+1-tree[node];
            if(nl!=nr){
                lazy[2*node+1]+=1;
                lazy[2*node+2]+=1;
            }
            return;
        }
        int mid=nl+(nr-nl)/2;
        update(2*node+1,nl,mid,l,r);
        update(2*node+2,mid+1,nr,l,r);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
    int query(int node,int nl,int nr,int l,int r){
        if(lazy[node]!=0){
            tree[node]=(lazy[node]&1?(nr-nl+1-tree[node]):tree[node]);
            if(nl!=nr){
                lazy[2*node+1]+=lazy[node];
                lazy[2*node+2]+=lazy[node];
            }
            lazy[node]=0;
        }
        if(nr<l||nl>r)return 0;
        if(nl>=l&&nr<=r)return tree[node];
        int mid=nl+(nr-nl)/2;
        return query(2*node+1,nl,mid,l,r)+query(2*node+2,mid+1,nr,l,r);
    }
};
void light(){
    int n,m;
    cin>>n>>m;
    SegmentTree seg(n);
    while(m--){
        int type;
        cin>>type;
        if(!type){
            int l,r;
            cin>>l>>r;
            l--,r--;
            seg.update(0,0,n-1,l,r);
        }else{
            int l,r;
            cin>>l>>r;
            l--,r--;
            cout<<seg.query(0,0,n-1,l,r)<<line;
            //for(auto &val:seg.lazy)cout<<val<<" ";
            cout<<line;
        }
    }
}
bool prime[N];
void sieve(){
    for(int i=2;i<N;i++)prime[i]=true;
    for(int i=2;i*i<N;i++){
        if(prime[i]){
            for(int j=i*i;j<N;j+=i){
                prime[j]=false;
            }
        }
    }
}
class segmentTree{
public:
    int n;
    vector<int>tree,lazy;
    segmentTree(int n){
        this->n=n;
        tree.resize(4*n);
        lazy.resize(4*n);
    }
    void build(int node,int nl,int nr,vector<int>&v){
        if(nl==nr){
            tree[node]=(prime[v[nl]]);
            return;
        }
        int mid=nl+(nr-nl)/2;
        build(2*node+1,nl,mid,v);
        build(2*node+2,mid+1,nr,v);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
    void lazy_set(int node,int nl,int nr,int l,int r,int newValue){
        if(lazy[node]!=0){
            tree[node]=(prime[lazy[node]]?nr-nl+1:0);
            if(nl!=nr){
                lazy[2*node+1]=lazy[node];
                lazy[2*node+2]=lazy[node];
            }
            lazy[node]=0;
        }
        if(nl>r||nr<l)return;
        if(nl>=l&&nr<=r){
            tree[node]=(prime[newValue]?nr-nl+1:0);
            if(nl!=nr){
                lazy[2*node+1]=newValue;
                lazy[2*node+2]=newValue;
            }
            return;
        }
        int mid=nl+(nr-nl)/2;
        lazy_set(2*node+1,nl,mid,l,r,newValue);
        lazy_set(2*node+2,mid+1,nr,l,r,newValue);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
    int query(int node,int nl,int nr,int l,int r){
        if(lazy[node]!=0){
            tree[node]=(prime[lazy[node]]?nr-nl+1:0);
            if(nl!=nr){
                lazy[2*node+1]=lazy[node];
                lazy[2*node+2]=lazy[node];
            }
            lazy[node]=0;
        }
        if(nl>r||nr<l)return 0;
        if(nl>=l&&nr<=r){
            return tree[node];
        }
        int mid=nl+(nr-nl)/2;
        return query(2*node+1,nl,mid,l,r)+query(2*node+2,mid+1,nr,l,r);
    }
};
void counting_prime(){
    int t;
    cin>>t;
    sieve();
    int ll=1;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>v(n);
        cout<<"Case "<<ll++<<":"<<line;
        for(auto &val:v)cin>>val;
        segmentTree seg(n);
        seg.build(0,0,n-1,v);
        while(m--){
            int type;
            cin>>type;
            if(!type){
                int l,r,value;
                cin>>l>>r>>value;
                l--,r--;
                seg.lazy_set(0,0,n-1,l,r,value);
            }else{
                int l,r;
                cin>>l>>r;
                cout<<seg.query(0,0,n-1,l-1,r-1)<<line;
            }
        }
    }
}
signed main() {
    khaled
    light();
}