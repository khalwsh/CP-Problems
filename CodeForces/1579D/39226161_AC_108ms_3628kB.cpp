#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=2e5+5;

int main() {
    FAST
   int t;
    cin>>t;
    while (t--) {
        int n;
        cin >> n;
        int x;
        priority_queue<tuple<int, int>> q;
        for (int i = 0; i < n; i++) {
            cin >> x;
                q.push(make_tuple(x, i + 1));
        }

        vector<tuple<int, int>> ans;
        while (get<0>(q.top())) {
            //cout << "yyyy\n";
            tuple<int, int> a = q.top();
            q.pop();
            if (q.empty()||get<0>(q.top()) == 0)
                break;
            tuple<int, int> b = q.top();
            q.pop();
            ans.push_back(make_tuple(get<1>(a), get<1>(b)));
            get<0>(a)--;
            get<0>(b)--;
                q.push(a);
                q.push(b);
        }

        cout<<ans.size()<<'\n';
        for(auto i:ans)
        {
            cout<<get<0>(i)<<' '<<get<1>(i)<<'\n';
        }
        cout<< '\n';

    }
    return 0;
}
