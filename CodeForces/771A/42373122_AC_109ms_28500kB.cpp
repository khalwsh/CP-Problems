#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
void mark_component(int node,vector<int>adj[],vector<int>&vis,int mark,vector<vector<int>>&component)
{
    vis[node]=true;
    component[mark].emplace_back(node);
    for(auto &val:adj[node])
    {
        if(!vis[val])
            mark_component(val,adj,vis,mark,component);
    }

}
int main() {
    khaled
    int n;
    int m;
    cin>>n>>m;
    vector<int>adj[n];
    int temp=m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    vector<vector<int>>component(n);vector<int>vis(n);
    int mark=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            mark_component(i,adj,vis,mark,component);
            mark++;
        }
    }
    bool flag=true;
    for(auto &val:component)
    {
        for(auto &i:val)
        {
            if(val.empty()||val.size()==1)
                continue;
            if(val.size()!=adj[i].size()+1)
                flag= false;
            if(!flag)
                break;
        }
        if(!flag)
            break;
    }
    if(flag)
        cout<<"YES";
    else
        cout<<"NO";
}