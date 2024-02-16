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
const int N=2e6+1;
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
int n,q;
int SQ;
vector<int>v;
vector<int>pre;
void build(){
    for(int i=0;i<SQ;i++){
        if(i*SQ>=n)break;
        sort(pre.begin()+i*SQ,pre.begin()+min((i+1)*SQ,n));
    }
}
int counter(int l,int r,int x){
    int res=0;
    for(int i=l;i<=r;i++){
        res+=(x>=v[i]);
    }
    return res;
}
int query(int l,int r,int x){
    int LB=l/SQ;
    int RB=r/SQ;
    if(LB==RB){
        return counter(l,r,x);
    }
    int res=0;
    for(int i=l;i<(LB+1)*SQ;i++){
        res+=(v[i]<=x);
    }
    for(int i=RB*SQ;i<=r;i++){
        res+=(v[i]<=x);
    }
    for(int i=LB+1;i<RB;i++){
        res+= upper_bound(pre.begin()+i*SQ,pre.begin()+i*SQ+SQ,x)-(pre.begin()+i*SQ);
    }
    return res;
}
void Modify(int pos,int x){
    int bId=pos/SQ;
    int bSt=bId*SQ;
    int bEn=min(n,bSt+SQ);
    int ind= lower_bound(pre.begin()+bSt,pre.begin()+bEn,v[pos])-pre.begin();
    v[pos]=x;
    pre[ind]=x;
    sort(pre.begin()+bSt,pre.begin()+bEn);
}
signed main() {
    khaled
    cin>>n>>q;
    SQ=(int)sqrt(n)+1;
    v.resize(n),pre.resize(n);
    for(auto &val:v)cin>>val;
    pre=v;
    build();
    while(q--){
        char type;
        cin>>type;
        if(type=='C'){
            //count
            int l,r,x;
            cin>>l>>r>>x;
            l--,r--;
            int res=query(l,r,x);
            cout<<res<<line;
        }else{
            //modify
            int l,r;
            cin>>l>>r;
            l--;
            Modify(l,r);
        }
    }
}