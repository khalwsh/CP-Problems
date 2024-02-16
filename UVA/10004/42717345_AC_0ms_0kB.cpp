#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
bool BFS(vector<int>adj[],int node,vector<int>&coloring)
{
    queue<int>q;
    q.push(node);
    coloring[node]=0;
    while(!q.empty())
    {
        int cur_node=q.front();
        q.pop();
        for(auto &val:adj[cur_node])
        {
            if(coloring[val]==-1)
                coloring[val]=!coloring[cur_node],q.push(val);
            else if(coloring[val]==coloring[cur_node])
                return false;
        }
    }
    return true;
}
bool DFS(int node,vector<int>adj[],vector<int>&coloring,int color)
{
    bool res=true;
    coloring[node]=color;
    for(auto &val:adj[node])
    {
        if(coloring[val]==-1)
        {
            res=res&&DFS(val,adj,coloring,!color);
        }
        else if(coloring[val]==coloring[node])
        {
             res=false;
        }
    }
    return res;
}
bool work(vector<int>adj[],int n)
{
    vector<int>coloring_second(n,-1);
    vector<int>coloring(n,-1);
    for(int i=0;i<n;i++)
    {
        if(coloring[i]==-1)
        {
            if(!(BFS(adj,i,coloring_second)&&DFS(i,adj,coloring,0)))
                return false;
        }
    }
    return true;
}
int main() {
    khaled
    while(true)
    {
        int n;
        cin>>n;
        if(n==0)
            break;
        int m;
        cin>>m;
        vector<int>adj[n];
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        if(work(adj,n))
            cout<<"BICOLORABLE.";
        else
            cout<<"NOT BICOLORABLE.";
        cout<<line;
    }
}