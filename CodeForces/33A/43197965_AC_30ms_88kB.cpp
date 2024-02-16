#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int n;
    int m;
    long long k;
    cin>>n>>m>>k;
    map<long long,long long>mp;
    for(int i=0;i<n;i++)
    {
        long long a,b;
        cin>>a>>b;
        if(mp.count(a)==0)
             mp[a]=b;
        else
            mp[a]=min(b,mp[a]);
    }
    long long res=0;
    vector<long long>v;
    for(auto &val:mp)
        v.emplace_back(val.second);
    sort(v.rbegin(),v.rend());
    for(int i=0;i<v.size();i++)
    {
        res+=min(k,v[i]);
        k-=min(k,v[i]);
        if(k==0)
            break;
    }
    cout<<res<<line;
}