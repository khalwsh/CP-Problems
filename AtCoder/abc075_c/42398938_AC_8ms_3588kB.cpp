#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
void DFS(int node,vector<int>adj[],vector<int>&vis)
{
    vis[node]=true;
    for(auto &val:adj[node])
    {
        if(!vis[val])
            DFS(val,adj,vis);
    }
}
bool if_one_component(vector<int>adj[],int n)
{
    vector<int>vis(n,0);
    DFS(0,adj,vis);
    for(int i=0;i<n;i++)
    {
       if(!vis[i])
           return false;
    }
    return true;
}
int main() {
    khaled
    int n;
    int m;
    cin>>n>>m;
    vector<pair<int,int>>edges;
    while(m--)
    {
       int x,y;
       cin>>x>>y;
       x--,y--;
       edges.emplace_back(x,y);
    }
    m=(int)edges.size();
    int counter=0;
    for(int i=0;i<m;i++)
    {
        vector<int>adj[n];
        for(int j=0;j<m;j++)
        {
            if(i==j)
                continue;
            adj[edges[j].first].emplace_back(edges[j].second);
            adj[edges[j].second].emplace_back(edges[j].first);
        }
        if(!if_one_component(adj,n))
            counter++;
    }
    cout<<counter<<line;
}