#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool valid(int x,int y,int n,int m)
{
    return x>=0&&x<n&&y>=0&&y<m;
}
bool can_go(int n,int m,vector<vector<char>>&grid)
{
    queue<pair<int,int>>q;
    q.push({0,0});
    vector<vector<bool>>vis(n,vector<bool>(m));
    vis[0][0]=false;
    while(!q.empty())
    {
        int row=q.front().first;
        int col=q.front().second;
        if(row==n-1&&col==m-1)
            return true;
        q.pop();
        if(!valid(row+1,col,n,m)&&!vis[row+1][col]&&grid[row+1][col]!='#')
            q.push({row+1,col}),vis[row+1][col]=true;
        if(!valid(row,col+1,n,m)&&!vis[row][col+1]&&grid[row][col+1]!='#')
            q.push({row,col+1}),vis[row+1][col]=true;
    }
    return false;
}
long long cal(long long n)
{
    if(n==1)
        return 0;
    if(n&1^1)
        return 1ll+cal(n/2);
    else
        return 1ll+cal(n-1);
}
signed main() {
    khaled
    /*int n;
    int m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(auto &val:grid)for(auto &i:val)cin>>i;
    if(!can_go(n,m,grid))
    {
        cout<<"0";
    }
    else
    {

    }*/
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int q;
        cin>>q;
        vector<long long>v(n);
        for(auto &val:v)
            cin>>val;
        vector<long long>twos;
        long long temp=1;
        twos.emplace_back(temp);
        while(temp<=1000000000000000000)
        {
            temp*=2ll;
            twos.emplace_back(temp);
        }
        vector<long long>need_operation(n,0);
        for(int i=0;i<n;i++)
        {
            need_operation[i]=cal(v[i]);
        }
        vector<long long>pref(n);
        pref[0]=need_operation[0];
        for(int i=1;i<n;i++)
            pref[i]=pref[i-1]+need_operation[i];
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            l--,r--;
            if(l==0)
                cout<<pref[r]<<line;
            else
                cout<<pref[r]-pref[l-1]<<line;
        }
    }

}
