#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int n;
    int m;
    int k;
    cin>>n>>m>>k;
    vector<int>adj[n];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    vector<pair<int,long long>>guards(k);
    vector<long long>remain(n,0);
    for(auto &[l,r]:guards)
        cin>>l>>r,l--,remain[l]=max(remain[l],r);
    vector<bool>vis(n,false);
    priority_queue<pair<long long,int>>q;//walk remain,node
    for(int i=0;i<n;i++)
    {
        if(remain[i]>0)
        {
            q.push({remain[i],i});
            vis[i]=true;
        }
    }
    while(!q.empty())
    {
        long long remain_walk=q.top().first;
        int node=q.top().second;
        q.pop();
        if(remain_walk<remain[node])continue;
        for(auto &val:adj[node])
        {
            if(remain_walk-1>=remain[val]&&remain_walk-1>=0)
            {
                if(remain_walk-1==remain[val]&&remain[val]!=0)
                    continue;
                vis[val]=true;
                remain[val]=remain_walk-1;
                q.push({remain_walk-1,val});
            }
        }
    }
    int counter=count(vis.begin(),vis.end(),true);
    cout<<counter<<line;
    for(int i=0;i<n;i++)
    {
        if(vis[i])
            cout<<i+1<<" ";
    }
    cout<<line;
}