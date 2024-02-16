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
const int N=4e6+1;
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
class Fenwick{
public:
    vector<int>tree;
    int n;
    Fenwick(int n){
        this->n=n;
        tree.resize(n+1);
    }
    void update(int node,int value){
        while(node<=n){
            tree[node]+=value;
            node+=node&-node;
        }
    }
    void build(vector<int>&v){
        for(int i=0;i<n;i++){
            update(i+1,v[i]);
        }
    }
    int query(int node){
        int sum=0;
        while(node>0){
            sum+=tree[node];
            node-=node&-node;
        }
        return sum;
    }
};
signed main() {
    khaled
    int t=1;
    while(true){
        int n;
        cin>>n;
        if(!n)break;
        if(t!=1)cout<<line;
        cout<<"Case "<<t++<<":"<<line;
        vector<int>v(n);
        for(auto &val:v)cin>>val;
        Fenwick fen(n);
        fen.build(v);
        while(true){
            char ch;
            cin>>ch;
            if(ch=='E'){
                string s;
                cin>>s;
                break;
            }
            if(ch=='M'){
                int l,r;
                cin>>l>>r;
                if(l>r)swap(l,r);
                cout<<fen.query(r)-fen.query(l-1)<<line;
            }else{
                int l,r;
                cin>>l>>r;
                fen.update(l,r-v[l-1]);
                v[l-1]=r;
            }
        }
    }
}