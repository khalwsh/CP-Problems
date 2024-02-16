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
int log2_floor(long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;}
const int N=1e6;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=2e17;
//__builtin_clzll(x): the number of zeros at the beginning of the number
//__builtin_ctzll(x): the number of zeros at the end of the number
//__builtin_popcountll(x): the number of ones in the number
//__builtin_parityll(x): the parity (even or odd) of the number of ones
/*=======================================================================================================*/
/*==============================================  KHALWSH  ==============================================*/
/*=======================================================================================================*/
class segment_tree{
public:
    vector<int>tree;
    int n;
    int no_operation=0;
    segment_tree(int n){
        this->n=n;
        this->tree.resize(this->n*4);
    }
    void build(int node,int nl,int nr,vector<int>&v){
        if(nl==nr){
            tree[node]=v[nl];
            return;
        }
        int mid=nl+(nr-nl)/2;
        build(2*node+1,nl,mid,v);
        build(2*node+2,mid+1,nr,v);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
    void update(int node,int nl,int nr,int v,int index){
        if(nr<index||nl>index)return;
        if(nl==nr&&nl==index){
            tree[node]+=v;
            return;
        }
        int mid=nl+(nr-nl)/2;
        update(2*node+1,nl,mid,v,index);
        update(2*node+2,mid+1,nr,v,index);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
    int query(int node,int nl,int nr,int l,int r){
        if(nl>=l&&nr<=r){
            return tree[node];
        }else if(nl>r||nr<l)return no_operation;
        int mid=nl+(nr-nl)/2;
        return query(2*node+1,nl,mid,l,r)+query(2*node+2,mid+1,nr,l,r);
    }
};
signed main() {
    khaled
    string s;
    cin>>s;
    int q;
    cin>>q;
    vector<segment_tree>trees(26,segment_tree((int)s.size()));
    for(int i=0;i<s.size();++i){
        trees[s[i]-'a'].update(0,0,(int)s.size()-1,1,i);
    }
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int pos;
            char c;
            cin>>pos;
            cin>>c;
            pos--;
            trees[s[pos]-'a'].update(0,0,(int)s.size()-1,-1,pos);
            s[pos]=c;
            trees[s[pos]-'a'].update(0,0,(int)s.size()-1,1,pos);
        }else{
            int l,r;
            cin>>l>>r;
            l--,r--;
            int res=0;
            for(int i=0;i<26;i++){
                if(trees[i].query(0,0,(int)s.size()-1,l,r))res++;
            }
            cout<<res<<line;
        }
    }
}