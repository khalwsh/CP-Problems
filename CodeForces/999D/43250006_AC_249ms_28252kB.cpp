#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
signed main() {
    khaled
    int n;
    int m;
    cin>>n>>m;
    vector<int>v(n);
    map<int,int>mp;
    for(auto &val:v)
        cin>>val,mp[val%m]++;
    vector<pair<int,int>>donner;
    vector<int>adj[m];
    for(int i=0;i<n;i++)
    {
        adj[v[i]%m].emplace_back(i);//mod to index
    }
    long long res=0;
    for (int i = 0; i < 2 * m; ++i) {
        while (mp[i%m] > n/m) {
            mp[i%m]--;
            donner.emplace_back(adj[i%m].back(), i);
            adj[i%m].pop_back();
        }
        while (mp[i%m]< n/m && !donner.empty()) {
            adj[i%m].push_back(donner.back().first);
            v[donner.back().first] += i - donner.back().second;
            res += i - donner.back().second;
            donner.pop_back();
            mp[i%m]++;
        }
    }
    cout<<res<<line;
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
}