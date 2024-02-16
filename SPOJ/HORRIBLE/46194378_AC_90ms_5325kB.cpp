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
struct Bit{
    int N=1<<18;
    vector<int>tree;
    void init(){
        tree.resize(this->N);
    }
    void add(int pos,int value){
        for(int i=pos+1;i<=N;i+=i&-i)tree[i-1]+=value;
    }
    int get(int pos) {
        int sum = 0;
        for (int i = pos + 1; i; i -= i & -i)sum += tree[i - 1];
        return sum;
    }
    int find(int t){
        int st=0;
        for(int sz=N>>1;sz;sz>>=1){
            if(tree[st+sz-1]<t){
                t-=tree[(st+=sz)-1];
            }
        }
        return st;
    }
};
struct MultiSet{
    Bit bit;
    MultiSet(){
        bit.init();
        bit.add(0,-1);
    }
    void insert(int value){
        bit.add(value,1);
    }
    void erase(int value){
        bit.add(value,-1);
    }
    int count(int value){
        return bit.get(value)-bit.get(value-1);
    }
    int size(){
        return bit.get(bit.N-1)+1;
    }
    int at(int index){
        return bit.find(index);//return the value which at index (index)
    }
};
struct BitRange{
    int N;
    vector<int>m,c;
    void init(int x){
        N=x;
        m.resize(N),c.resize(N);
    }
    void add(int pos,int mVal,int cVal){
        for(++pos;pos<=N;pos+=pos&-pos){
            m[pos-1]+=mVal;
            c[pos-1]+=cVal;
        }
    }
    int get(int pos){
        int ret=0;
        int x=pos;
        for(pos++;pos;pos-=pos&-pos){
            ret+=m[pos-1]*x+c[pos-1];
        }
        return ret;
    }
    void addRange(int l,int r,int value){
        add(l,value,-value*(l-1));
        add(r+1,-value,value*r);
    }
};
signed main() {
    khaled
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        BitRange bit;
        bit.init(n+1);
        while(q--){
            int type;
            cin>>type;
            int l,r;
            cin>>l>>r;
            if(type==0){
                int value;
                cin>>value;
                l--,r--;
                bit.addRange(l,r,value);
            }else{
                l--,r--;
                cout<<bit.get(r)-bit.get(l-1)<<line;
            }
        }
    }
}