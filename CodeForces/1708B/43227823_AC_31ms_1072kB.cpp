#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        int l, r;
        cin >> l >> r;
        {
            vector<int> res;
            int temp=n;
            int i=1;
            while (n--) {
                if(((l-1)/i+1)*i<=r) {
                    res.emplace_back(((l-1)/i+1)*i);
                    i++;
                }
                else
                    break;
            }
            if (res.size() != temp)
                cout << "NO"<<line;
            else {
                cout << "YES";
                cout << line;
                for (auto &val: res)
                    cout << val << " ";
                cout << line;
            }
        }
    }
}