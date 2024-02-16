#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
int black_counter=0,red_counter=0;
void dfs_count(int node,int parent,vector<int>adj[],vector<int>&colors)
{
    for(auto &val:adj[node])
    {
        if(parent==val)
            continue;
        black_counter+=colors[val]==2,red_counter+=colors[val]==1, dfs_count(val,node,adj,colors);
    }
}
long long final_res=0;
pair<int, int> dfs_mark_sub_tree(int v,int p,vector<int>adj[],vector<int>&a,vector<pair<int,int>>&res)
{
        int r = (a[v] == 1), b = (a[v] == 2);
        for (auto u : adj[v]) {
            if (u == p)
                continue;
            pair<int,int> tmp = dfs_mark_sub_tree(u, v, adj, a, res);
            final_res += (tmp.first == red_counter && tmp.second == 0);
            final_res += (tmp.first == 0 && tmp.second == black_counter);
            r += tmp.first;
            b += tmp.second;
        }
        return make_pair(r, b);
}
int main() {
    khaled
    int n;
    cin>>n;
    vector<int>colors(n);
    for(auto &val:colors)
        cin>>val;
    vector<int>adj[n];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<pair<int,int>>res(n);
    vector<int>vis(n);
    red_counter=(int)count(colors.begin(),colors.end(),1);
    black_counter=(int)count(colors.begin(),colors.end(),2);
    dfs_mark_sub_tree(0,-1,adj,colors,res);
    cout<<final_res<<line;
}