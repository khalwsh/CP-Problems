#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
signed main() {
    khaled
    int n;
    cin>>n;
    int mp[500];
    for(auto &val:mp)
        val=0;
    long long res=0;
    vector<int>s;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;//o(400*n*log(n))
        if(i>=1)
        {
            for(auto &val:s)
            {
                res+=mp[val+200]*((x-val)*(x-val));
            }
        }
        if(mp[x+200]==0)
            s.emplace_back(x);
        mp[x+200]++;
    }
    cout<<res<<line;
}