#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod=1e9+7;
long long dfs(int node,int parent,vector<int>adj[],long long remain_colors,int intial_count)
{
    long long consumed=1;//i counsmed a color
    long long temp=remain_colors;
    if(node!=0)consumed++;
    for(auto &val:adj[node])
    {
        if(parent==val)continue;
        temp=((temp%mod)*(dfs(val,node,adj,intial_count-consumed,intial_count)%mod))%mod;
        consumed++;
    }
    return temp;
}
int main() {
    khaled
    int n;
    cin>>n;vector<int>adj[n];long long k;cin>>k;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    cout<<dfs(0,-1,adj,k,k);
}