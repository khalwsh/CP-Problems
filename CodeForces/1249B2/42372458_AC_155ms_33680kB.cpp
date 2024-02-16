#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
void DFS_size(int node,vector<int>adj[],vector<int>&vis1,int &counter)
{
    vis1[node]=true;
    counter++;
    for(auto &val:adj[node])
    {
        if(!vis1[val])
            DFS_size(val,adj,vis1,counter);
    }
}
void DFS_mark(int node,vector<int>adj[],vector<int>&vis2,int mark,vector<int>&res)
{
    vis2[node]=true;
    res[node]=mark;
    for(auto &val:adj[node])
    {
        if(!vis2[val])
            DFS_mark(val,adj,vis2,mark,res);
    }
}
int main() {
    khaled
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        vector<int>adj[n];
        vector<int>component(n);
        vector<int>vis1(n),vis2(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            adj[i].emplace_back(v[i]-1);
        }
        vector<int>res(n);
        for(int i=0;i<n;i++)
        {
            int counter=0;
            if(!vis1[i])
            {
                DFS_size(i,adj,vis1,counter);
            }
            if(!vis2[i])
            {
                DFS_mark(i,adj,vis2,counter,res);
            }
        }
        for(auto &val:res)
            cout<<val<<" ";
        cout<<line;
    }

}