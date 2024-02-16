#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool valid(int i,int j,int n,int m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &mod=INT64_MAX){
    if(power==0)return 1ll;long long d= fast_power(base,power/2)%mod;d=mul(d,d,mod);if(power&1)return mul(d,base,mod);else return d;}
long long mod_inverse_fermat(long long B,const long long&mod=1e9+7){ return fast_power(B,mod-2);}//mod is prime
int dx[]{1,-1,0,0,1,1,-1,-1};//0->4 normal,4->8 diagonal
int dy[]{0,0,1,-1,1,-1,1,-1};
//#define int long long
/*--------------------------------------------------------------------------------------------------------------------*/
class dsu{
public:
    vector<int>parent,siz;
    dsu(int n)
    {
        parent.resize(n);
        siz.resize(n,1);
        for(int i=0;i<n;i++)
            parent[i]=i;
    }
    int find_parent(int child)
    {
        return (parent[child]==child?child:parent[child]=find_parent(parent[child]));
    }
    void merge(int a,int b)
    {
        a= find_parent(a);
        b= find_parent(b);
        if(a==b)return;
        if(siz[a]<siz[b])
            parent[a]=b,siz[b]+=siz[a];
        else
            parent[b]=a,siz[a]+=siz[b];
    }
};
signed main() {
    khaled
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int m;
        cin>>n>>m;
        dsu d(n);
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            a--,b--;
            d.merge(a,b);
        }
        int my_max=0;
        for(auto &val:d.siz)
        {
            my_max=max(val,my_max);
        }
        cout<<my_max<<line;
    }
}


