#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
bool valid(int node,int n)
{
    return node>0&&node<=n;
}
vector<int>BFS(int n,vector<int>&short_cuts)
{
    queue<pair<int,pair<int,int>>>q;//state node parent;//0 forward 1 backward 2 short_cut
    vector<vector<bool>>vis(3,vector<bool>(n+1));//3 states coming forward,backward,short_cut
    vector<int>res(n+1,-1);
    q.push({1,{1,0}});
    vis[1][1]=vis[0][1]=vis[2][1]=true;
    while(!q.empty())
    {
        int state=q.front().first;
        int node=q.front().second.first;
        int parent=q.front().second.second;
        q.pop();
        if(res[node]==-1)
            res[node]=res[parent]+1;
        else
            res[node]=min(res[node],res[parent]+1);
        if(valid(node+1,n)&&!vis[0][node+1])
        {
            vis[0][node+1]=true;
            q.push({0,{node+1,node}});
        }
        if(valid(node-1,n)&&!vis[1][node-1])
        {
            vis[1][node-1]=true;
            q.push({1,{node-1,node}});
        }
        if(valid(node,n)&& valid(short_cuts[node],n)&&!vis[2][short_cuts[node]])
        {
            vis[2][short_cuts[node]]=true;
            q.push({2,{short_cuts[node],node}});
        }

    }
    return res;
}
int main() {
    khaled
    int n;
    cin>>n;
    vector<int>short_cuts(n+10);
    for(int i=1;i<=n;i++)
        cin>>short_cuts[i];
    vector<int>distance=BFS(n,short_cuts);
    for(int i=1;i<=n;i++)
        cout<<distance[i]<<" ";
    cout<<line;
}