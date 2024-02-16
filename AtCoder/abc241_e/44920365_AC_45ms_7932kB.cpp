#include<bits/stdc++.h>
using namespace std;
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define line '\n'
#define int long long
signed main() {
    khaled
    int n;
    int k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &val:v)cin>>val;
    vector<int> vis (n,-1), res (n,0);
    int x = 0;
    for(int i=0;i<k;i++) {
        if (vis[x%n]!=-1) {
            int cycle_length = i - vis[x%n];
            if ((k - i) % cycle_length == 0) {
                x += ((k - i) / cycle_length)*(x - res[x%n]);
                break;
            }
        }
        vis[x%n] = i;
        res[x%n] = x;
        x += v[x%n];
    }
    cout << x << line ;
}