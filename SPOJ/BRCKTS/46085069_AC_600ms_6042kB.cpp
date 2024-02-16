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
const long long inf=9e18;
//__builtin_clzll(x): the number of zeros at the beginning of the number
//__builtin_ctzll(x): the number of zeros at the end of the number
//__builtin_popcountll(x): the number of ones in the number
//__builtin_parityll(x): the parity (even or odd) of the number of ones
/*=======================================================================================================*/
/*==============================================  KHALWSH  ==============================================*/
/*=======================================================================================================*/
class SegmentTree{
public:
    struct Node{
        int open,close;
        Node(){
            open=close=0;
        }
        void assign(int o,int c){
            open=o,close=c;
        }
        Node operator+(Node x){
            Node ans;
            int t=min(open,x.close);
            ans.open=x.open+open-t;
            ans.close=x.close+close-t;
            return ans;
        }
    };
    int n;
    vector<Node>tree;
    SegmentTree(int n){
        this->n=n;
        tree.resize(this->n*4);
    }
    void build(int node,int nl,int nr,string&s){
        if(nl==nr){
            tree[node].assign(s[nl]=='(',s[nl]==')');
            return;
        }
        int mid=nl+(nr-nl)/2;
        build(2*node+1,nl,mid,s);
        build(2*node+2,mid+1,nr,s);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
    void update(int node,int nl,int nr,int index){
        if(nl==nr&&nl==index){
            tree[node].assign(1-tree[node].open,1-tree[node].close);
            return;
        }
        if(nl>index||nr<index)return ;
        int mid=nl+(nr-nl)/2;
        update(2*node+1,nl,mid,index);update(2*node+2,mid+1,nr,index);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
    bool check(){
        return tree[0].open==0&&tree[0].close==0;
    }
};
signed main() {
    khaled
    int n;
    int counter=1;
    while(cin>>n){
        string s;
        cin>>s;
        int q;
        cin>>q;
        cout<<"Test "<<counter++<<":"<<line;
        SegmentTree seg(n);
        seg.build(0,0,n-1,s);
        while(q--){
            int type;
            cin>>type;
            if(type==0){
                //check
                cout<<(seg.check()?"YES":"NO");
                cout<<line;
            }else{
                //update
                seg.update(0,0,n-1,type-1);
            }
        }
    }
}