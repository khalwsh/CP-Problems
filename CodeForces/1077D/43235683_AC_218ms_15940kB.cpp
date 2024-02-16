#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    map<int,int>mp;
    for(auto &val:v)
        cin>>val,mp[val]++;
    vector<pair<int,int>>vp;
    for(auto &val:mp)
        vp.emplace_back(val.second,val.first);
    priority_queue<pair<int,int>>pq;
    vector<int>res;
    for(auto &val:vp)
        pq.push(val);
    map<int,int>rep;
    while(k--)
    {
        int repeat=pq.top().first;
        int node=pq.top().second;
        rep[node]++;
        pq.pop();
        res.emplace_back(node);
        pq.push({mp[node]/(rep[node]+1),node});
    }
    for(auto &val:res)
        cout<<val<<" ";
    cout<<line;

}