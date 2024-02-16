#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
void dikstra(int n,vector<pair<int,int>>adj[],vector<long long>&dist,int source)
{
    dist[source]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    pq.push({0,source});
    while(!pq.empty())
    {
        int node=pq.top().second;
        int cost=pq.top().first;
        pq.pop();if(cost!=dist[node])continue;
        for(auto &val:adj[node])
        {
            if(dist[val.first]>cost+val.second)
            {
                dist[val.first]=cost+val.second;
                pq.push({dist[val.first],val.first});
            }
        }
    }
}
signed main() {
    khaled
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj1[n];vector<pair<int,int>>adj2[n];
    map<pair<int,int>,int>mp;
    for(int i=0;i<m;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        if(!mp.count(make_pair(a,b)))
            mp[make_pair(a,b)]=c;
        else
            mp[make_pair(a,b)]=min(mp[make_pair(a,b)],c);

    }
    for(auto &val:mp)
        adj1[val.first.first].emplace_back(val.first.second,val.second),adj2[val.first.second].emplace_back(val.first.first,val.second);
    vector<long long>dist1(n,INT64_MAX),dist2(n,INT64_MAX);
    dikstra(n,adj1,dist1,0);dikstra(n,adj2,dist2,n-1);
    long long res=INT64_MAX;
    for (int c = 0; c < n; c++) {
        for (auto [va, nc] : adj1[c]) {
            if (dist1[c] == INT64_MAX || dist2[va] == INT64_MAX) {
                continue;
            }
            res =std::min(res, dist1[c] + (nc / 2) + dist2[va]);
        }
    }
    cout<<res<<line;
}
/*
 * 4 4
1 2 200
1 3 20
2 4 200
3 4 400
 */