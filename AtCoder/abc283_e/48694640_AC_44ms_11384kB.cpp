#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int long long
#define double long double
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
bool valid(long long i,long long j,long long n,long long m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &m=INT64_MAX){if (power == 1 || power == 0)return base * power + (!power);long long res = (fast_power(base, power / 2, m) % m) % m;if (power & 1)return mul(base,mul(res,res,m),m);else return mul(res,res,m);}
int log2_floor(long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : 0;}
int power_of_2(int n){ return __builtin_popcountll(n)==1;}
bool line_checking(int a1,int b1,int a2,int b2,int a3,int b3) { return (b2-b1)*(a2-a3)==(b2-b3)*(a2-a1); }
pair<int,int> rotate(int i,int j,int n){ return make_pair(j,n-1-i); }
const int N=2e5+5;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=8e18+1;
int dx[]{1,-1,0,0,1,1,-1,-1};
int dy[]{0,0,1,-1,1,-1,1,-1};
const double pi=3.14159265350979323846,eps=1e-8;
/*==============================================  KHALWSH  ==============================================*/
int n,m;
int v[1001][1001];
int dp[1001][2][2];
int solve(int row,bool before,bool now){
    if(row == n){
        return 0;
    }
    bool NextFlip = true;
    bool NextNotFlip = true;
    int &res = dp[row][before][now] ;
    if(~res)return res;
    res= inf;
    if(before){
        if(now){
            for(int i = 0;i<m;i++){
                int c = 0;
                for(int j=1;j<4;j++){
                    int ni = row + dx[j];
                    int nj = i + dy[j];
                    if(valid(ni,nj,n,m)&&v[ni][nj]==v[row][i])c++;
                }
                if(c==0){
                    if(row == n-1)return res = inf;
                    if(v[row+1][i]==v[row][i])NextNotFlip = false;
                    else NextFlip = false;
                }
            }
            if(NextNotFlip)res = min(res,solve(row+1,now,false)+1);
            if(NextFlip)res = min(res,solve(row+1,now,true)+1);
        }else{
            for(int i = 0;i<m;i++){
                int c = 0;
                for(int j=2;j<4;j++){
                    int ni = row + dx[j];
                    int nj = i + dy[j];
                    if(valid(ni,nj,n,m)&&v[ni][nj]==v[row][i])c++;
                }
                int j = 1;
                int ni = row + dx[j];
                int nj = i + dy[j];
                if(valid(ni,nj,n,m)&&v[ni][nj]!=v[row][i])c++;
                if(c==0){
                    if(row == n-1)return res = inf;
                    if(v[row+1][i]==v[row][i])NextFlip = false;
                    else NextNotFlip = false;
                }
            }
            if(NextNotFlip)res = min(res,solve(row+1,now,false));
            if(NextFlip)res = min(res,solve(row+1,now,true));
        }
    }else{
        if(now){
            for(int i = 0;i<m;i++){
                int c = 0;
                for(int j=2;j<4;j++){
                    int ni = row + dx[j];
                    int nj = i + dy[j];
                    if(valid(ni,nj,n,m)&&v[ni][nj]==v[row][i])c++;
                }
                int j = 1;
                int ni = row + dx[j];
                int nj = i + dy[j];
                if(valid(ni,nj,n,m)&&v[ni][nj]!=v[row][i])c++;
                if(c==0){
                    if(row == n-1)return res = inf;
                    if(v[row+1][i]==v[row][i])NextNotFlip = false;
                    else NextFlip = false;
                }
            }
            if(NextNotFlip)res = min(res,solve(row+1,now,false)+1);
            if(NextFlip)res = min(res,solve(row+1,now,true)+1);
        }else{
            for(int i = 0;i<m;i++){
                int c = 0;
                for(int j=1;j<4;j++){
                    int ni = row + dx[j];
                    int nj = i + dy[j];
                    if(valid(ni,nj,n,m)&&v[ni][nj]==v[row][i])c++;
                }
                if(c==0){
                    if(row == n-1)return res = inf;
                    if(v[row+1][i]==v[row][i])NextFlip = false;
                    else NextNotFlip = false;
                }
            }
            if(NextNotFlip)res = min(res,solve(row+1,now,false));
            if(NextFlip)res = min(res,solve(row+1,now,true));
        }
    }
    return res;
}
signed main() {
    khaled
    cin>>n>>m;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>v[i][j];
    int res = inf;
    res = min(solve(0,false,false),solve(0,false,true));
    res = (res>=inf?-1:res);
    cout<<res<<line;
}