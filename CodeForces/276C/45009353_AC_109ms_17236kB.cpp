#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl "\n";
const long long N = 2e5 + 5, MOD = 1e9 + 7, OO = 1e18;
const double PI = acos(-1);
 
long long n, a[N], b[N] ,q[N], l, r, m;
string a1[N], b1[N];
map<long long, int>mp;
 
int main()
{
    IO
    cin >> n >> m;
    long long sum = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++){
        cin >> l >> r;
        q[l]++;
        q[r + 1]--;
    }
    for(int i = 1; i <= n; i++) q[i] += q[i - 1];
    sort(a + 1, a + n + 1);
    sort(q + 1, q + n + 1);
    for(int i = 1; i <= n; i++) sum += a[i] * q[i];
    cout << sum << endl;
    return 0;
}