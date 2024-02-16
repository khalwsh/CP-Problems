#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool check_line(int a1,int b1,int a2,int b2,int a3,int b3){return (a3-a1)*(b2-b1)==(a2-a1)*(b3-b1);}
bool valid(int i,int j,int n,int m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &mod=INT64_MAX){if(power==0)return 1ll;long long d= fast_power(base,power/2)%mod;d=mul(d,d,mod);if(power&1)return mul(d,base,mod);else return d;}
long long mod_inverse_fermat(long long B,const long long&mod=1e9+7){ return fast_power(B,mod-2);}//mod is prime
int dx[]{1,-1,0,0,1,1,-1,-1};//0->4 normal,4->8 diagonal
int dy[]{0,0,1,-1,1,-1,1,-1};
#define int long long
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
bool can(int days,int power,vector<int>heights,vector<int>cur)
{
    if(count(cur.begin(),cur.end(),0)!=0)
    {
        for(auto &val:cur)
        {
            if(val==0&&power==0)
                return false;
            else if(val==0&&power)
                power--,val=1;
            else
                val++;
        }
        days--;
    }
    for(int i=0;i<cur.size();i++)
    {
        if(cur[i]>=heights[i])continue;
        if(heights[i]-cur[i]>days)
        {
            int needed=heights[i]-cur[i]-days;
            if((needed+1)/2<=days&&needed<=power)
                power-=needed;
            else
                return false;
        }
    }
    return true;
}
signed main() {
    khaled
    int t;
    freopen("different.in","rt",stdin);
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x;
        int k;
        cin>>k;
        cin>>x;
        long long all=x/k;
        vector<int>heights(n);
        for(auto &val:heights){
            cin>>val;
        }
        vector<int>cur(n);for(auto &val:cur)cin>>val;
        long long res=-1;
        long long left=0;
        long long right=1e9;
        while(left<=right)
        {
            long long mid=left+(right-left)/2;
            if(can(mid,min(all,mid),heights,cur))
                res=mid,right=mid-1;
            else
                left=mid+1;
        }
        cout<<res<<endl;
    }
}

