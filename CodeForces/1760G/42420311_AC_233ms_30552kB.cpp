#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
void mark_for_a(long long node,long long parent,vector<pair<long long,long long>>adj[],long long res,set<long long>&xor1,bool flag=false,int b=0)
{
    if(node==b)
        return;
    xor1.insert(res);
    for(auto &val:adj[node])
    {
        if(parent==val.first)
            continue;
        mark_for_a(val.first,node,adj,res^val.second,xor1,true,b);
    }
}
void mark_for_b(long long node,long long parent,vector<pair<long long,long long>>adj[],long long res,set<long long>&xor2,bool flag=false)
{
    if(flag)
        xor2.insert(res);
    for(auto &val:adj[node])
    {
        if(parent==val.first)
            continue;
        mark_for_b(val.first,node,adj,res^val.second,xor2,true);
    }
}
signed main()
{
    khaled
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        a--,b--;
        vector<pair<long long,long long>>adj[n];//edge and weight
        for(int i=1;i<n;i++)
        {
            long long u,v;
            cin>>u>>v;u--,v--;
            long long x;
            cin>>x;
            adj[u].emplace_back(v,x);
            adj[v].emplace_back(u,x);
        }
        set<long long>xor1;
        set<long long>xor2;
        mark_for_a(a,-1,adj,0,xor1,false,b);
        mark_for_b(b,-1,adj,0,xor2,false);
        bool flag=false;
        for(auto &val:xor2)
        {
            if(xor1.count(val)) {
                flag = true;
                break;
            }
        }
        if(flag)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<line;
    }
}