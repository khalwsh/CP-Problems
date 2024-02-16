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
const int N=2e4+1;
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
long double dist(long double a1,long double a2,long double b1,long double b2){
    return sqrt((b1-a1)*(b1-a1)+(b2-a2)*(b2-a2));
}
long double dp[9][1<<8];
int vis[9][1<<8];
int tx=1;
long double solve(int index,int targets,vector<pair<long double,long double>>&vp){
    if(targets==0)return 0;
    long double res=1e11;
    long double &ret=dp[index][targets];
    if(vis[index][targets]==tx)return ret;
    vis[index][targets]=tx;
    for(int i=0;i<vp.size();i++){
        if(targets&(1<<i)){
            long double temp=dist(vp[index].first,vp[index].second,vp[i].first,vp[i].second);
            res=min(res,solve(i,targets^(1<<i),vp)+temp+16.0);
        }
    }
    return ret = res;
}
vector<pair<pair<long long,long long>,pair<long long,long long>>>connections;
void build(int index,int targets,vector<pair<long double,long double>>&vp){
    if(targets==0)return ;
    long double res;
    vis[index][targets]=tx;
    for(int i=0;i<vp.size();i++){
        if(targets&(1<<i)){
            long double temp=dist(vp[index].first,vp[index].second,vp[i].first,vp[i].second);
            res=solve(i,targets^(1<<i),vp)+temp+16.0;
            if(res==dp[index][targets]){
                connections.push_back({{vp[index].first,vp[index].second},{vp[i].first,vp[i].second}});
                build(i,targets^(1<<i),vp);
                return;
            }
        }
    }
}
signed main() {
    khaled
    int t=1;
    while(true){
        int n;
        cin>>n;
        if(!n)break;
        cout<<"**********************************************************"<<line;
        cout<<"Network"<<" #"<<t++<<line;
        vector<pair<long double,long double>>points(n);
        connections.clear();
        for(auto &val:points)cin>>val.first>>val.second;
        cout<<fixed<<showpoint<<setprecision(2);
        long double res=1e13;
        int ind=0;
        for(int i=0;i<n;i++){
            //saying this is the start;
            if(solve(i,((1<<n)-1)^(1<<i),points)<res){
                res=solve(i,((1<<n)-1)^(1<<i),points);
                ind=i;
            }
        }
        build(ind,((1<<n)-1)^(1<<ind),points);
        for(auto &val:connections){
            long double temp=dist(val.first.first,val.first.second,val.second.first,val.second.second)+16.0;
            cout<<"Cable requirement to connect ("<<val.first.first<<","<<val.first.second<<
            ") to ("<<val.second.first<<","<<val.second.second<<") is "<<
            temp<<" feet."<<line;
        }
        cout<<"Number of feet of cable required is "<<res<<"."<<line;
        tx++;
    }
}