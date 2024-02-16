#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
bool DFS(int node,int yellow,vector<int>adj[],vector<int>&color)
{
    color[node]=yellow;
    bool res=true;
    for(auto &val:adj[node])
    {
        if(color[val]==-1)
        {
            res=res&&DFS(val,!yellow,adj,color);
        }else if(color[val]==color[node])
            res=false;
    }
    return res;
}bool check_if_colored(int n,vector<int>adj[],vector<int>&colors)
{
    for(auto &val:colors)
        val=-1;
    for(int i=0;i<n;i++)
    {
        if(colors[i]==-1)
        {
            if(!DFS(i,0,adj,colors))
                return false;
        }
    }
    return true;

}
int main() {
    khaled
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    vector<pair<int,int>>edges(m);
    for(int i=0;i<m;i++)
    {
        cin>>edges[i].first>>edges[i].second;
        edges[i].first--,edges[i].second--;
        adj[edges[i].first].emplace_back(edges[i].second);
        adj[edges[i].second].emplace_back(edges[i].first);
    }
    vector<int>colors(n);
    if(!check_if_colored(n,adj,colors))
        cout<<"NO";
    else
    {
        cout<<"YES";
        cout<<line;
        queue<pair<int,int>>q;//node and it's direction
        q.emplace(edges.front().first,0);
        vector<int>dire(n,-1);
        dire[edges.front().first]=0;
        while(!q.empty())
        {
            int node=q.front().first;
            int direction=q.front().second;
            q.pop();
            for(auto &val:adj[node])
            {
                if(dire[val]==-1)
                    dire[val]=!direction,q.emplace(val,dire[val]);
            }
        }
        string res;
        for(auto &val:edges)
        {
            res+=to_string(dire[val.first]);
        }
        cout<<res<<line;

    }
}