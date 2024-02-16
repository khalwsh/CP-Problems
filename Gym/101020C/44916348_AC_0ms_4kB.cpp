#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int M = 101;
 
void solution() {
    int n; cin >> n;
 
    vector<int> pre(M, 0);
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (a > b) swap(a, b);
        for (int j = a; j < b; j++) {
            pre[j] = max(pre[j], c);
        }
    }
 
    int ans = 0;
    for (int i = 0; i < M; i++) {
        ans += pre[i];
    }
 
    cout << ans << '\n';
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
 
    int t = 1; cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}