#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool valid(int i,int j,int n,int m)
{
    return i>=0&&i<n&&j>=0&&j<m;
}
bool i_need(string &temp,string&s)
{
    for(int i=0;i<temp.size();i++)
    {
        if(s[i]!=temp[i])
            return false;
    }
    return true;
}
signed main() {
    khaled
    int n;
    cin>>n;
    vector<vector<char>>v(n,vector<char>(n));
    for(auto &val:v)for(auto &i:val)cin>>i;
    queue<pair<int,pair<int,string>>>q;
    vector<vector<bool>>vis(n,vector<bool>(n,false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]=='I')
            {
                q.push(make_pair(i, make_pair(j,"I")));
                vis[i][j]=true;
            }
        }
    }
    bool work=false;
    string res="ICPCASIASG";
    while(!q.empty())
    {
        int row=q.front().first;
        int col=q.front().second.first;
        string temp=q.front().second.second;
        if(temp==res)
        {
            work=true;break;
        }
        q.pop();
        int dx[]{-1,-2,1,2,-1,-2,1,2};
        int dy[]{2,1,2,1,-2,-1,-2,-1};
        for(int i=0;i<8;i++)
        {
            int cur_row=row+dx[i];
            int cur_col=col+dy[i];
            if(valid(cur_row,cur_col,n,n)&&!vis[cur_row][cur_col])
            {
                vis[cur_row][cur_col]=true;
                temp+=v[cur_row][cur_col];
                q.push({cur_row, make_pair(cur_col,temp)});
                temp.pop_back();
            }
            else if(valid(cur_row,cur_col,n,n)&&vis[cur_row][cur_col]&&i_need(temp,res))
            {
                temp+=v[cur_row][cur_col];
                q.push({cur_row, make_pair(cur_col,temp)});
                temp.pop_back();
            }
        }
    }
    if(work)
        cout<<"YES";
    else
        cout<<"NO";
}
