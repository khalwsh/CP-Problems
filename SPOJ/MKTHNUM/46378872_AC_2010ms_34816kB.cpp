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
struct node{
    vector<int>v;
    node operator+(const node&a2){
        node res;
        int p1=0,p2=0;
        while(p1<v.size()&&p2<a2.v.size()){
            if(v[p1]<a2.v[p2])res.v.emplace_back(v[p1]),p1++;
            else res.v.emplace_back(a2.v[p2]),p2++;
        }
        while(p1<v.size())res.v.emplace_back(v[p1]),p1++;
        while(p2<a2.v.size())res.v.emplace_back(a2.v[p2]),p2++;
        return res;
    }
    void merge(const node&a,const node&b){
        std::merge(a.v.begin(),a.v.end(),b.v.begin(),b.v.end(),inserter(v,v.begin()));

    }
};
struct SegmentTree{
    vector<node>tree;
    int n;
    SegmentTree(int n){
        this->n=n;
        tree.resize(n*4);
    }
    void build(int nd,int nl,int nr,vector<int>&v){
        if(nl==nr){
            tree[nd].v.emplace_back(v[nl]);
            return;
        }
        int mid=nl+(nr-nl)/2;
        build(2*nd+1,nl,mid,v);
        build(2*nd+2,mid+1,nr,v);
        tree[nd].merge(tree[2*nd+1],tree[2*nd+2]);
    }
    int query(int nd,int nl,int nr,int l,int r,int value){
        if(nl>r||nr<l)return 0;
        if(nl>=l&&nr<=r)return lower_bound(tree[nd].v.begin(),tree[nd].v.end(),value)-tree[nd].v.begin();
        int mid=nl+(nr-nl)/2;
        return query(2*nd+1,nl,mid,l,r,value)+query(2*nd+2,mid+1,nr,l,r,value);
    }
};
signed main() {
    khaled
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(auto &val:v)cin>>val;
    SegmentTree seg(n);
    seg.build(0,0,n-1,v);
    while(m--){
        int l,r,k;
        cin>>l>>r>>k;
        l--,r--;
        int left=-1e9,right=1e9;
        int res=-inf;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(seg.query(0,0,n-1,l,r,mid)>=k)res=mid,right=mid-1;
            else left=mid+1;
        }
        cout<<res-1<<endl;
    }
}
