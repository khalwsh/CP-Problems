#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
vector<int>res;
void dfs_traversal(int node,int parent,vector<int>adj[])
{
    res.emplace_back(node);
    for(auto &val:adj[node])
    {
        if(parent==val)
            continue;
        dfs_traversal(val,node,adj);
    }
   // if(res.back()!=node)
   if(parent!=-1)
       res.emplace_back(parent);
}
int main() {
    khaled
    int n;
    cin>>n;
    vector<int>adj[n];
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a-1].emplace_back(b-1);
        adj[b-1].emplace_back(a-1);
    }
    for(auto &val:adj)
        sort(val.begin(),val.end());
    dfs_traversal(0,-1,adj);
    for(auto &val:res)
        cout<<val+1<<" ";

}