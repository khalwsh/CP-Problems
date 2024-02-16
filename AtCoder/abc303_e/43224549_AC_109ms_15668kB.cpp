#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int BFS(vector<int>&total_degree,vector<int>adj[],int n,int start)
{
    queue<pair<int,int>>q;//node and parent
    q.push({start,-1});
    vector<int>del;
    vector<int>dist(n,0);
    dist[start]=0;
    int counter=0;
    while(!q.empty())
    {
        int siz=(int)q.size();
        while(siz--)
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto &val:adj[node])
            {
                if(val==parent)continue;
                if(val!=-2&&dist[val]==0)
                {
                    dist[val]=dist[node]+1;
                    q.push({val,node});
                    if(dist[val]>2)
                     counter++,del.emplace_back(val);
                }
            }
        }
    }
    for(auto &val:del)
        adj[val].clear();
    return counter;
}
int main() {
    khaled
    int n;
    cin>>n;
    vector<int>adj[n];
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    vector<int>res;
    int sum=0;
    for(int i=0;i<n;i++){
        if(adj[i].size()>=3){//if a node has more than two children so it must be a center
            sum+=(int)adj[i].size()+1;//i cut all of the nodes it self+it's children and count the start as the number of children
            res.push_back((int)adj[i].size());
        }
    }
    int m=n-sum;//the remaining nodes have only two children so every three of remaining nodes forming a star by itself
    while(m){
        res.push_back(2);
        m-=3;
    }
    sort(res.begin(),res.end());
    for(auto &val:res)
        cout<<val<<" ";
    cout<<line;
}