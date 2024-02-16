#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=2e5+5;
 
int main() {
    FAST
    int t;
    cin>>t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        // 6 3 4
      //  1 2 4 7 6 3
        int x;
        multiset<int> s;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            cin >> x;
            s.insert(x); /// 3 6 7
            if (s.size() == m) {
                ans.push_back(*s.begin());
                s.erase(s.begin());
            }
        }
        while (!s.empty())
        {
            ans.push_back(*s.begin());
            s.erase(s.begin());
        }
        cout<<ans[k-1]<<'\n';
    }
    return 0;
}