#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void solve(long long A,long long B,long long n)
{
    vector<long long>a(n),b(n);
    for(auto &val:a)
        cin>>val;
    for(auto &val:b)
        cin>>val;
    long long loss = 0;
    for (int i = 0; i < n; ++i)
        loss += (b[i] + A - 1) / A * a[i];
    for (int i = 0; i < n; ++i) {
        if (B - (loss - a[i]) > 0) {
            cout << "YES";
            return;
        }
    }
    cout<<"NO";
}
signed main() {
    khaled
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        int n;
        cin>>n;
        solve(a,b,n);
        cout<<line;
    }
}
