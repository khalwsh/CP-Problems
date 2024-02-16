#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
int depth[1000007];
void mark_depth(int node,int parent,vector<int>adj[])
{
    if(parent >= 0)
        depth[node] = depth[parent] + 1;
    for(int u:adj[node]){
        if(u == parent) continue;
        mark_depth(u, node, adj);
    }
}
int DFS(int node,int parent,vector<int>adj[],vector<bool>&with_me)
{
    int res = 0;
    bool lower = false;
    for(int val: adj[node]){
        if(val == parent) continue;
        res += DFS(val, node,adj, with_me);
        lower = lower || with_me[val];
    }
    with_me[node] = with_me[node] || lower;
    if(with_me[node] && !lower) 
        res = 1;
    return res;
}
int main()
{
    khaled
    int n;
    cin>>n;
    vector<int>adj[n];
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x-1].emplace_back(y-1);
        adj[y-1].emplace_back(x-1);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int k;
        memset(depth,0,sizeof(depth));
        mark_depth(0,-1,adj);
        cin>>k;
        vector<bool> chosen(n);
        int mx = 0;
        for(int i = 0; i < k; ++i){
            int x;
            cin >> x;
            x--;
            if(depth[x] > depth[mx])
                mx = x;
            chosen[x] = true;
        }
        int leaves = DFS(mx, -1, adj, chosen);
        if(leaves == 1) cout << "YES";
        else cout << "NO";
        cout<<line;

    }
}