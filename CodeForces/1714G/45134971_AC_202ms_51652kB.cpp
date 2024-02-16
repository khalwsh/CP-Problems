#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
void DFS_mark_A(int node,int parent,vector<long long>&A,vector<pair<int,pair<int,int>>>adj[],long long summation)
{
    A[node]=summation;
    for(auto &val:adj[node])
    {
        if(val.first==parent)
            continue;
        DFS_mark_A(val.first,node,A,adj,summation+val.second.first);
    }
}
int binary_search(vector<long long>&path,long long value)
{
    int left=0;
    int right=(int)path.size()-1;
    long long res=0;
    while(left<=right)
    {
        long long mid=left+(right-left)/2;
        if(path[mid]<=value)
        {
            res=mid;
            left=mid+1;
        }
        else
            right=mid-1;
    }
    return res;
}
void DFS_mark_for_B(int node,int parent,vector<long long>&A,vector<pair<int,pair<int,int>>>adj[],vector<int>&path,long long summation,vector<long long>&res)
{
    path.push_back(summation);
    for(auto &val:adj[node])
    {
        if(parent==val.first)
            continue;
        DFS_mark_for_B(val.first,node,A,adj,path,summation+val.second.second,res);
    }
    res[node]=binary_search(path,A[node]);
    path.pop_back();
}
signed main()
{
    khaled
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,pair<int,int>>>adj[n];//from index to node and first is a cost second is b cost
        for(int j=1;j<n;j++)
        {
            int u;
            int a_cost,b_cost;
            cin>>u>>a_cost>>b_cost;
            u--;
            adj[j].emplace_back(u, make_pair(a_cost,b_cost));
            adj[u].emplace_back(j, make_pair(a_cost,b_cost));
        }
        vector<long long>A(n);
        DFS_mark_A(0,-1,A,adj,0);
        vector<long long>res(n);
        vector<int>path;
        DFS_mark_for_B(0,-1,A,adj,path,0,res);
        for(int i=1;i<n;i++)
            cout<<res[i]<<" ";
        cout<<line;
    }

}