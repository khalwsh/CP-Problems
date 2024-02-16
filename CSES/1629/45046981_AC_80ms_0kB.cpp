#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool valid(int i,int j,int n,int m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const int&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const int&mod){return (((x%mod)+(y%mod))+mod)%mod;}
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
#define int long long
/*--------------------------------------------------------------------------------------------------------------------*/
vector<pair<int,int>>v;
bool comp(pair<int,int>&a,pair<int,int>&b)
{
    return a.second<b.second;
}
signed main() {
    khaled
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.emplace_back(x,y);
    }
    sort(v.begin(),v.end(),comp);
    int counter=1;
    int cur_time=v[0].second;
    for(int i=1;i<n;i++)
    {
        if(cur_time<=v[i].first)
        {
            cur_time=v[i].second;
            counter++;
        }
    }
    cout<<counter<<line;
}