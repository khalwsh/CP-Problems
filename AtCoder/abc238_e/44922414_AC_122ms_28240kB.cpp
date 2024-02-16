#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1E9;
 
void solution() {
    int n, q; cin >> n >> q;
 
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < q; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v + 1);
adj[v+1].emplace_back(u);
    }
 
    bool can = false;
    vector<int> vis(n+1, 0);
    function<void(int)> dfs = [&] (int u) {
        if (u == n) {
            can = true;
            return;
        }
        vis[u] = 1;
        for (auto v : adj[u]) {
            if (!vis[v]) dfs(v);
        }
    };
    dfs(0);
 
    cout << (can ? "Yes\n" : "No\n");
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
 
    int t = 1; // cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}