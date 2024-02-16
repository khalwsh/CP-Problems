#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int t;
    cin>>t;
    while(t--) {
        string l, r;
        cin >> l >> r;
        while (l.size() < r.size())
            l = '0'+l;
        int res = 0;
        bool done = false;
        for (int i = 0; i < r.size(); ++i) {
            if (!done) {
                res += abs(r[i] - l[i]);
                done = l[i] != r[i];
            } else res += 9;
        }
        cout << res << line;
    }
}
