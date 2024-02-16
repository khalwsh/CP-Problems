#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
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
bool valid(int a,int b,int c,int k,int n,int m)
{
    return a>=0&&a<k&&b>=0&&b<n&&c>=0&&c<m;
}
int d[]{1,-1};
void DFS(int a,int b,int c,int k,int n,int m,vector<vector<vector<char>>>&v,vector<vector<vector<bool>>>&vis)
{
    vis[a][b][c]=true;
    v[a][b][c]='k';
    for(int i=0;i<=1;i++)
    {
        if(valid(a+d[i],b,c,k,n,m)&&!vis[a+d[i]][b][c]&&v[a+d[i]][b][c]!='#')
            DFS(a+d[i],b,c,k,n,m,v,vis);
        if(valid(a,b+d[i],c,k,n,m)&&!vis[a][b+d[i]][c]&&v[a][b+d[i]][c]!='#')
            DFS(a,b+d[i],c,k,n,m,v,vis);
        if(valid(a,b,c+d[i],k,n,m)&&!vis[a][b][c+d[i]]&&v[a][b][c+d[i]]!='#')
            DFS(a,b,c+d[i],k,n,m,v,vis);
    }
}
int main()
{
    khaled
    int k,n,m;
    cin>>k>>n>>m;
    vector<vector<vector<char>>>v(k,vector<vector<char>>(n,vector<char>(m)));
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int l=0;l<m;l++)
            {
                cin>>v[i][j][l];
            }
        }
    }
    int x,y;
    cin>>x>>y;
    x--;
    y--;
    vector<vector<vector<bool>>>vis(k,vector<vector<bool>>(n,vector<bool>(m)));
    DFS(0,x,y,k,n,m,v,vis);
    int counter=0;
    for(auto &val:v)
    {
        for(auto &i:val)
        {
            for(auto &l:i)
                if(l=='k')
                    counter++;
        }
    }
    cout<<counter<<line;
}