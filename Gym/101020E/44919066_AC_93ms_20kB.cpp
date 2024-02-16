#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1E9;
 
void solution() {
    int t, n; cin >> t >> n;
    while (t--) {
        int a, b, x, y; cin >> a >> b >> x >> y;
        if (a == x && b == y) {
            cout << 0 << '\n';
            continue;
        }
        if ((a + b) % 2 != (x + y) % 2) {
            cout << "can't reach!\n";
            continue;
        }
        const int dx[] = {1, 1, -1, -1};
        const int dy[] = {-1, 1, -1, 1};
        auto valid = [&] (int u, int v) -> bool {
            return u >= 0 && u < n && v >= 0 && v < n;
        };
        vector<vector<int>> d(n, vector<int> (n, inf));
        d[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int l = x, r = y;
            while (valid(l + dx[i], r + dy[i])) {
                d[l + dx[i]][r + dy[i]] = d[l][r] + 1;
                l += dx[i];
                r += dy[i];
            }
        }
        d[a][b] = 0;
        int ans = inf;
        for (int i = 0; i < 4; i++) {
            int l = a, r = b;
            while (valid(l + dx[i], r + dy[i])) {
                if (d[l + dx[i]][r + dy[i]] != inf) {
                    ans = min(ans, d[l][r] + d[l + dx[i]][r + dy[i]]);
                    break;
                }
                d[l + dx[i]][r + dy[i]] = d[l][r] + 1;
                l += dx[i];
                r += dy[i];
            }
        }
        cout << ans << '\n';
    }
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