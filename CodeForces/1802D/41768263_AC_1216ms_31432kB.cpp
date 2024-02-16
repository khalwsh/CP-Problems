#include <bits/stdc++.h>
#define fast cin.tie(0), ios::sync_with_stdio(false)
long long const INF=1e18;
using namespace std;
void solve()
{
    int n; cin >> n;
    vector<pair<long long,long long>> v(n);
    multiset<long long> s;
    for(int i=0; i < n; ++i) cin >> v[i].first >> v[i].second,s.insert(v[i].second);
    sort(v.begin(),v.end(),greater<>());
    long long mx=-INF;
    long long ans =INF;
    for(int i=0; i < n; ++i)
    {
        s.erase(s.lower_bound(v[i].second));
        auto u = s.lower_bound(v[i].first);
        auto y = u;
        if(y != s.begin()) y--;
        if(u == s.end() || abs(*u-v[i].first) > abs(*y-v[i].first)) u=y;
        if(mx > *u) ans=min(ans,abs(mx-v[i].first));
        else ans=min(ans,min(abs(mx-v[i].first),abs(*u-v[i].first)));
        mx=max(mx,v[i].second);
    }
    cout << ans << "\n";
}
int main()
{

    fast;
    int T=1; cin >> T;
    while(T--) solve();
}