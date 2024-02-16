#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
int main() {
    khaled
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> d(n, INT_MAX);
    d[0] = 0;
    vector<int> p(n);
    p[0] = -1;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto child: adj[node]) {
            if (d[child] > d[node] + 1) {
                d[child] = d[node] + 1;
                p[child] = node;
                q.push(child);
            }
        }
    }

    cout << "Yes\n";
    for (int i = 1; i < n; i++) {
        cout << p[i] + 1 << '\n';
    }
}