#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int n;
    int v;
    cin>>n>>v;
    vector<vector<int>>sellers(n);
    for(int i=0;i<n;i++)
    {
        long long k;
        cin>>k;
        while(k--)
        {
            long long a;
            cin>>a;
            sellers[i].emplace_back(a);
        }
    }
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        bool work=false;
        for(auto &val:sellers[i])
        {
           if(val<v)
               work=true;
        }
        if(work)
            res.emplace_back(i+1);
    }
    cout<<res.size()<<line;
    for(auto &val:res)
        cout<<val<<" ";

}