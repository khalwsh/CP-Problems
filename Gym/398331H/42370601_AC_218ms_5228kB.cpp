#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
void DFS(int node,vector<int>adj[],vector<int>&vis,vector<int>&freq,int start)
{
    vis[node]=true;
    freq[node]=start;
    for(auto &val:adj[node])
    {
        if(!vis[val])
            DFS(val,adj,vis,freq,start);
    }
}
int main() {
    khaled
    int t;
    cin>>t;
    while(t--)
    {
        vector<int>freq;
        int n,m;
        cin>>n>>m;
        freq.resize(n);
        int q;
        cin>>q;
        vector<int>adj[n];
        vector<vector<int>>component;
        while(m--)
        {
            int x,y;
            cin>>x>>y;
            x--,y--;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        vector<int>vis(n);
        int start=1;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                DFS(i,adj,vis,freq,start);
                start++;
            }
        }
        string s;
        while(q--) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            if(x==y||freq[x]==freq[y])
                s+='1';
            else
                s+='0';
        }
        cout<<s<<line;
    }
}