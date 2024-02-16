#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
void DFS(int node,vector<int>adj[],vector<int>&vis,stack<int>&res)
{
    vis[node]=true;
    for(auto &val:adj[node])
    {
        if(!vis[val])
            DFS(val,adj,vis,res);
    }
    res.push(node);

}
vector<int>topological_sorting(vector<int>adj[],int n)
{
    vector<int>res;
    stack<int>temp;
    vector<int>vis(n);
    for(int i=0;i<n;i++)
    {
        if(!vis[i]) {
            DFS(i, adj, vis, temp);
        }
    }
    while (!temp.empty())
        res.emplace_back(temp.top()), temp.pop();
    return res;
}
int main() {
    khaled
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    vector<int> in_degree(n);
    priority_queue<int> q;//to make the largest value equal to largest valid label
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[b].push_back(a);//reverse the graph so the out degree become in degree
        in_degree[a]++;
    }
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) 
            q.push(i);
    }
    vector<int> res(n);
    while (!q.empty()) {
        int node = q.top(); q.pop();
        res[node] = n--;
        for (auto val : adj[node]) {
            in_degree[val]--;//BFS topological sorting 
            if (in_degree[val] == 0) {
                q.push(val);
            }
        }
    }
    for (auto val : res)
        cout << val << " ";
}