#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<long long,long long>>vp(n);
        for(auto &[l,r]:vp)cin>>l;
        for(auto &[l,r]:vp)cin>>r;
        vector<long long>differ;//the richest with the poorest
        for(auto &val:vp)differ.emplace_back(val.second-val.first);
        sort(differ.rbegin(),differ.rend());
        int rich=0,poor=n-1;
        int res=0;
        while(rich<poor)
        {
            if(differ[rich]+differ[poor]>=0)res++,rich++,poor--;
            else poor--;
        }
        cout<<res<<line;
    }

}