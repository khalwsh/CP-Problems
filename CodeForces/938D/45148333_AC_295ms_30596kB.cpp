#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
signed main() {
    khaled
    int n,m;
    cin>>n>>m;
    vector<pair<long long,long long>>adj[n];
    for(int i=0;i<m;i++)
    {
        long long a,b;
        cin>>a>>b;
        long long cost;
        cin>>cost;
        a--,b--;
        cost*=2ll;
        adj[a].emplace_back(b,cost);
        adj[b].emplace_back(a,cost);
    }
    vector<long long>tickets(n);
    for(auto &val:tickets)
        cin>>val;
    vector<long long>dist(n,0);
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>>pq;
    for(int i=0;i<n;i++)
        dist[i]=tickets[i],pq.push({dist[i],i});
    while(!pq.empty())
    {
        long long node=pq.top().second;
        long long cost=pq.top().first;
        pq.pop();
        if(dist[node]!=cost)continue;
        for(auto &val:adj[node])
        {
            if(dist[val.first]>cost+val.second)
                dist[val.first]=cost+val.second,pq.push({dist[val.first],val.first});
        }
    }
    for(auto &val:dist)
        cout<<val<<" ";
}