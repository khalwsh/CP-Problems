#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
int my_min=INT_MAX;
void DFS(int node,vector<int>&vis,vector<int>&costs,vector<int>adj[])
{
    vis[node]=true;
    my_min=min(my_min,costs[node]);
    for(auto &val:adj[node])
    {
        if(!vis[val])
            DFS(val,vis,costs,adj);
    }
}
signed main() {
    khaled
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int>cost(n);
    for(auto &val:cost)
        cin>>val;
    vector<int>adj[n];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    int res=0;
    vector<int>vis(n,false);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            my_min=INT_MAX;
            DFS(i,vis,cost,adj);
            res+=my_min;
        }
    }
    cout<<res<<line;
}