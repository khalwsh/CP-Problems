#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
int BFS(vector<int>adj[],int n)
{
    queue<int>q;
    q.push(0);
    vector<int>dist(n,-1);
    dist[0]=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto &val:adj[node])
        {
            if(dist[val]==-1)
                dist[val]=dist[node]+1,q.push(val);
            else
                dist[val]=min(dist[val],dist[node]+1);
        }
    }

    return dist[n-1];
}
int main() {
    khaled
    int n;
    int m;
    cin>>n>>m;
    vector<int>adj_rail_way[n];
    int adj_for_bus[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                adj_for_bus[i][j]=0;
            else
                adj_for_bus[i][j]=1;
        }
    }
    while(m--)
    {
       int x,y;
       cin>>x>>y;
       x--,y--;
       adj_for_bus[x][y]=0;
       adj_for_bus[y][x]=0;
       adj_rail_way[x].emplace_back(y);
       adj_rail_way[y].emplace_back(x);
    }
    vector<int>adj_bus[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(adj_for_bus[i][j]==1)
                adj_bus[i].emplace_back(j);
        }
    }
   /* for(int i=0;i<n;i++)
    {
        for(auto &val:adj_bus[i])
            cout<<val<<" ";
        cout<<line;
    }*/
    if(adj_for_bus[0][n-1]==1)
    {
        int res=BFS(adj_rail_way,n);
        cout<<res<<line;
    }
    else
    {
        int res= BFS(adj_bus,n);
        cout<<res<<line;
    }
}