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
const int N=2e5+1;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=9e18;
//__builtin_clzll(x): the number of zeros at the beginning of the number
//__builtin_ctzll(x): the number of zeros at the end of the number
//__builtin_popcountll(x): the number of ones in the number
//__builtin_parityll(x): the parity (even or odd) of the number of ones
/*=======================================================================================================*/
/*==============================================  KHALWSH  ==============================================*/
/*=======================================================================================================*/
struct Node{
    int zeros,plus,minus;
    Node(){
        zeros=plus=minus=0;
    }
    void assign(int z,int p,int m){
        zeros=z,plus=p,minus=m;
    }
};
class segment{
public:

public:
    int n;
    vector<Node>tree;
    segment(int n){
        this->n=n;
        tree.resize(this->n*4);
    }
    Node merge(Node left,Node right){
        Node temp;
        temp.zeros=left.zeros+right.zeros;
        temp.minus=left.minus+right.minus;
        temp.plus=right.plus+left.plus;
        return temp;
    }
    void build(int node,int nl,int nr,vector<int>&v){
        if(nl==nr){
            tree[node].assign(v[nl]==0,v[nl]>0,v[nl]<0);
            return;
        }
        int mid=nl+(nr-nl)/2;
        build(2*node+1,nl,mid,v);build(2*node+2,mid+1,nr,v);
        tree[node]= merge(tree[2*node+1],tree[2*node+2]);
    }
    void update(int node,int nl,int nr,int index,int value){
        if(nl==nr&&index==nl){
            if(value==0){
                if(tree[node].zeros==1)return;
                else tree[node].assign(1,0,0);
            }else if(value>0){
                if(tree[node].plus==1)return;
                else tree[node].assign(0,1,0);
            }else{
                if(tree[node].minus==1)return;
                else tree[node].assign(0,0,1);
            }
            return ;
        }
        if(nr<index||nl>index)return;
        int mid=nl+(nr-nl)/2;
        update(2*node+1,nl,mid,index,value);
        update(2*node+2,mid+1,nr,index,value);
        tree[node]= merge(tree[2*node+1],tree[2*node+2]);
    }
    Node querying(int node,int nl,int nr,int l,int r){
        if(nl>r||nr<l)return Node();
        if(nl>=l&&nr<=r)return tree[node];
        int mid=nl+(nr-nl)/2;
        Node left= querying(2*node+1,nl,mid,l,r);
        Node right= querying(2*node+2,mid+1,nr,l,r);
        return merge(left,right);
    }
};
signed main() {
    khaled
    int n;
    bool flag=false;
    while(cin>>n){
        int k;
        cin>>k;
        flag=true;
        vector<int>v(n);
        for(auto &val:v)cin>>val;
        segment seg(n);
        seg.build(0,0,n-1,v);
        string s;
        while(k--){
            char ch;
            int l,r;
            cin>>ch;
            cin>>l>>r;
            if(ch=='C'){
                //change command
                l--;
                seg.update(0,0,n-1,l,r);
            }else if(ch=='P'){
                //query command
                l--,r--;
                Node q=seg.querying(0,0,n-1,l,r);
                if(q.zeros!=0){
                    s+='0';
                }else if(q.minus&1)
                    s+='-';
                else
                    s+='+';
            }
        }
        cout<<s<<line;
    }
}