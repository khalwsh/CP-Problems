#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
void mark_dist(int node,int parent,vector<int>adj[],vector<int>&dist,int distance)
{
    dist[node]=distance;
    for(auto &val:adj[node])
    {
        if(val==parent)
            continue;
        mark_dist(val,node,adj,dist,distance+1);
    }
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
    int counter_first=0,counter_second=0;
    vector<int>dist1(n),dist2(n);
    mark_dist(0,-1,adj,dist1,0);
    mark_dist(n-1,-1,adj,dist2,0);
    for(int i=0;i<n;i++)
    {
        if(dist1[i]>dist2[i])counter_second++;
        else
            counter_first++;//the idea is simple if you manage to reach after me so i would be already coloring it before you 
    }
    if(counter_first>counter_second)
        cout<<"Fennec";
    else
        cout<<"Snuke";
}