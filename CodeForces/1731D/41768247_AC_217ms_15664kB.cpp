#include <bits/stdc++.h>
#define fast cin.tie(0), ios::sync_with_stdio(false)
long long const INF=1e18;
using namespace std;
bool fun(int x,vector<vector<int>> &v)
{
    int n = v.size(),m=v[0].size();
    vector<vector<int>> pre(n+1,vector<int> (m+1,0));
    for(int i=1; i <= n; ++i)
        for(int j=1; j <= m; ++j)
            if(v[i-1][j-1] >= x) pre[i][j]=1;
    for(int i=0; i <= n; ++i)
        for(int j=1; j <= m; ++j) pre[i][j]+=pre[i][j-1];
    for(int i=0; i <= m; ++i)
        for(int j=1; j <= n; ++j) pre[j][i]+=pre[j-1][i];
    for(int i=1; i <= n; ++i)
        for(int j=1; j <= m; ++j)
        {
            if(i-x < 0 || j - x < 0) continue;
            int g = pre[i][j]-pre[i-x][j]-pre[i][j-x]+pre[i-x][j-x];
            if(g == x*x) return true;
        }
    return false;
}
void solve()
{
    int n,m; cin >> n >> m ;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0; i < n; ++i)
        for(int j=0; j < m; ++j) cin >> v[i][j];
    int l=1,r=min(n,m),ans;
    while(r >= l)
    {
        int mid=l+(r-l)/2;
        if(fun(mid,v)) l=mid+1,ans=mid;
        else r=mid-1;
    }
    cout << ans << endl;
}
int main()
{

    fast;
    int T=1; cin >> T;
    while(T--) solve();
}