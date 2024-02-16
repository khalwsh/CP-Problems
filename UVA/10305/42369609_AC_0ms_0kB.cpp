#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
void DFS_sort(int node,vector<int>adj[],vector<int>&vis,stack<int>&sk)
{
    vis[node]=true;
    for(auto &val:adj[node])
    {
        if(!vis[val])
            DFS_sort(val,adj,vis,sk);
    }
    sk.push(node);
}
int main() {
    khaled
    int n;
    int m;
    while(true) {
        cin >> n >> m;
        if(n==0&&m==0)
            break;
        vector<int> adj[n];
        vector<int> vis(n);
        while (m--) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            adj[x].emplace_back(y);
        }
       
        stack<int> sk;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                DFS_sort(i, adj, vis, sk);
            }
        }
        while (!sk.empty()) {
            cout << sk.top() + 1 << " ";
            sk.pop();
        }
        cout<<line;
    }
}