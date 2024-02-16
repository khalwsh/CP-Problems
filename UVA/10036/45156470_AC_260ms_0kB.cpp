#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool valid(int i,int j,int n,int m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))+mod)%mod;}
long long fast_power(long long base,long long power,const long long &mod=INT64_MAX){
    if(power==0)return 1ll;long long d= fast_power(base,power/2)%mod;d=mul(d,d,mod);if(power&1)return mul(d,base,mod);else return d;}
long long mod_inverse_fermat(long long B,const long long&mod=1e9+7){ return fast_power(B,mod-2);}//mod is prime
int dx[]{1,-1,0,0,1,1,-1,-1};//0->4 normal,4->8 diagonal
int dy[]{0,0,1,-1,1,-1,1,-1};
#define int long long
/*--------------------------------------------------------------------------------------------------------------------*/
int dp[10007][100];
bool solve(int index,int n,int k,vector<int>&v,int mod)
{
    if(index==n)
        return mod%k==0;
    if(dp[index][mod]!=-1)return dp[index][mod];
    int res1=solve(index+1,n,k,v,(((mod+v[index])%k+k)%k));
    int res2=solve(index+1,n,k,v,(((mod-v[index])%k+k)%k));
    return dp[index][mod]=res1||res2;
}
signed main() {
    khaled
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        for(auto &val:v)cin>>val;
        for(int i=0;i<k;i++){
            dp[n][i]=(i%k==0);
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<k;j++){
                int res1=dp[i+1][(((j+v[i])%k+k)%k)];
                int res2=dp[i+1][(((j-v[i])%k+k)%k)];
                dp[i][j]=res1||res2;
            }
        }
        if(dp[1][(v[0]%k+k)%k])
            cout<<"Divisible";
        else
            cout<<"Not divisible";
        cout<<line;
    }
}

