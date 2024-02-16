#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
void BFS_mark(int root,vector<int>adj[],vector<long long>&mark)
{
    queue<pair<int,int>>q;
    q.push({root,-1});
    mark[root]=0;
    while(!q.empty())
    {
        int sz=(int)q.size();
        while(sz--)
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto &val: adj[node]) {
                if (parent == val)continue;
                q.push({val, node});
                mark[val]=mark[node]+1;
            }
        }
    }


}
int main() {
    khaled
    int n;
    cin>>n;
    vector<int>adj[n];
    long long police_start,theif_start;
    cin>>theif_start>>police_start;
    theif_start--,police_start--;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<long long>theif_dist(n);
    vector<long long>police_dist(n);
    BFS_mark(theif_start,adj,theif_dist);
    BFS_mark(police_start,adj,police_dist);
    long long my_max_node=-1;
    for(int i=0;i<n;i++)
    {
        if(theif_dist[i]<police_dist[i])
        {
            my_max_node=max(police_dist[i],my_max_node);
        }
    }
    cout<<my_max_node-1;
}