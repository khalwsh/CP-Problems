#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
void dfs_mark(int node,int parent,vector<int>adj[],vector<int>&res,vector<bool>&vis)
{
    vis[node]=true;
    for(auto &val:adj[node])
    {
        if(!vis[val])
        {
            res[val]=node;
            dfs_mark(val,node,adj,res,vis);
        }
    }
}
int main() {
    khaled
    int n,r1,r2;
    cin>>n>>r1>>r2;
    r1--;r2--;
    vector<int>adj[n];
    for(int i=0;i<n;i++)
    {
        if(i==r1)continue;
        int x;
        cin>>x;
        x--;
        adj[i].emplace_back(x);
        adj[x].emplace_back(i);
    }
    vector<int>mark(n);vector<bool>vis(n);
    dfs_mark(r2,-1,adj,mark,vis);
    for(int i=0;i<n;i++)
    {
        if(i==r2)
            continue;
        cout<<mark[i]+1<<" ";
    }
    cout<<line;

}