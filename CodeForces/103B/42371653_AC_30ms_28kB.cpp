#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
void multicompontent1(int node,vector<int>adj[],vector<int>&vis)
{
   vis[node]=true;
   for(auto &val:adj[node])
   {
       if(!vis[val])
           multicompontent1(val,adj,vis);
   }

}
bool multicompontent(int node,vector<int>adj[],vector<int>&vis)
{
    multicompontent1(0,adj,vis);
    return count(vis.begin(),vis.end(),false)!=0;
}
bool DFS_cycle(int node,int parent,vector<int>adj[],vector<int>&vis)
{
    vis[node]=true;
    bool res=false;
    for(auto &val:adj[node])
    {
        if(!vis[val])
          res=res||DFS_cycle(val,node,adj,vis);
        else if(val!=parent)
            res=true;
    }
    return res;
}
int main() {
    khaled
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    int temp=m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int>vis(n);
    bool res= DFS_cycle(0,-1,adj,vis);
   for(auto &val:vis)
       val=0;
    if(!res||multicompontent(0,adj,vis))
        cout<<"NO";
    else
    {
        if(n==temp)
            cout<<"FHTAGN!";
        else
            cout<<"NO";
    }

}