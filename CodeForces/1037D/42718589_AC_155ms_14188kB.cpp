#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
int index[200007];
bool cmp(int a,int b){
    return index[a]<index[b];//sort the children as their appears in the targeting BFS and every level by it's own unique nodes
}
int main() {
    khaled
    int n;
    cin>>n;
    vector<int>adj[n];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
    }

    for(auto &val:adj)
        sort(val.begin(),val.end(),cmp);
    vector<int>BFS(n);
    int counter=0;
    for(auto &val:BFS)
        cin>>val,val-=1,index[val]=counter++;
    for(auto &val:adj)
        sort(val.begin(),val.end(),cmp);
    queue<int>q;
    vector<int>vis(n);
    vis[BFS[0]]=true;
    q.push(0);
    int index=1;
    vector<int>res;
    while(!q.empty())
    {
        int node=q.front();
        res.emplace_back(node);
        if(res.size()==n)
            break;
        q.pop();
        for(auto &val:adj[node])
            if(!vis[val])
                q.push(val),vis[val]=true;
    }
    cout<<((BFS==res)?"Yes":"No");
}