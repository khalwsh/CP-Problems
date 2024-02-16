
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
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=2e17+1;
//__builtin_clzll(x): the number of zeros at the beginning of the number
//__builtin_ctzll(x): the number of zeros at the end of the number
//__builtin_popcountll(x): the number of ones in the number
//__builtin_parityll(x): the parity (even or odd) of the number of ones
/*=======================================================================================================*/
/*==============================================  KHALWSH  ==============================================*/
/*=======================================================================================================*/
struct Node{

   int Max,MaxLeft,MaxRight,sum;

   Node(int d=0,int a=-inf,int b=-inf,int c=-inf){
      sum=d;
      Max=a;
      MaxLeft=b;
      MaxRight=c;
   }
   //node parent= left + right
   Node operator+(const Node&a){
      Node res;
      res.sum=a.sum+sum;
      res.MaxLeft=max(MaxLeft,sum+a.MaxLeft);
      res.MaxRight=max(a.MaxRight,a.sum+MaxRight);
      res.Max=max({a.Max,Max,MaxRight+a.MaxLeft});
      return res;
   }
};
struct SegementTree{
    vector<Node>tree;
    int n;
    SegementTree(int _n){
       n=_n;
       tree.resize(4*n);
    }
    void build(int node,int nl,int nr,vector<int>&v){
       if(nl==nr){
         tree[node]=Node(v[nl],v[nl],v[nl],v[nl]);
         return ;
       }
        int mid=nl+(nr-nl)/2;
        build(2*node+1,nl,mid,v);
        build(2*node+2,mid+1,nr,v);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
    void update(int node,int nl,int nr,int index,int newValue){
        if(nl==nr&&nl==index){
            tree[node]=Node(newValue,newValue,newValue,newValue);
            return ;
        }
        if(nl>index||nr<index)return;
        int mid=nl+(nr-nl)/2;
        update(2*node+1,nl,mid,index,newValue);
        update(2*node+2,mid+1,nr,index,newValue);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
    Node query(int node,int nl,int nr,int l,int r){
        if(nl>=l&&nr<=r)return tree[node];
        if(nl>r||nr<l)return Node();
        int mid=nl+(nr-nl)/2;
        return query(2*node+1,nl,mid,l,r)+query(2*node+2,mid+1,nr,l,r);
    }
};
signed main() {
    khaled
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &val:v)cin>>val;
    int m;
    SegementTree seg(n);
    seg.build(0,0,n-1,v);
    cin>>m;
    while(m--){


        int type;
        cin>>type;
        if(type==0){
            int index;
            cin>>index;
            index--;
            int newValue;
            cin>>newValue;
            seg.update(0,0,n-1,index,newValue);
        }else{

          int l,r;
          cin>>l>>r;
          if(l>r)swap(l,r);
          l--,r--;
          cout<<seg.query(0,0,n-1,l,r).Max<<line;
        }

    }

}
