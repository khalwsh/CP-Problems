#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
bool valid(int i,int j,int n,int m)
{
    return i>=0&&i<n&&j>=0&&j<m;
}
int dx[]{0,0,-1,1};
int dy[]{1,-1,0,0};
bool work=false;
void DFS(int i,int j,int prev_i,int prev_j,int n,int m,vector<vector<char>>&v,vector<vector<bool>>&vis,char like_me,int& counter)
{
    vis[i][j]=true;
    counter++;
    for(int l=0;l<4;l++)
    {
        int next_row=i+dx[l];
        int next_col=j+dy[l];
        if(valid(next_row,next_col,n,m)&&!vis[next_row][next_col]&&v[next_row][next_col]==like_me)
           DFS(next_row,next_col,i,j,n,m,v,vis,like_me,counter);
        else if(valid(next_row,next_col,n,m)&&vis[next_row][next_col]&&!(next_col==prev_j&&next_row==prev_i)&&v[next_row][next_col]==like_me)
            work=true;
    }
}
int main()
{
    khaled
    int n;
    int m;
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    for(auto &val:v)
    {
        for(auto &i:val)
            cin>>i;
    }
    vector<vector<bool>>vis(n,vector<bool>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int counter=0;
            if(!vis[i][j]) {
                DFS(i, j, -1, -1, n, m, v, vis, v[i][j], counter);
                //cout<<v[i][j];
                if (counter<4)
                    work=false;
            }
            if(work)
                break;
        }
        if(work)
            break;
    }
    if(work)
        cout<<"Yes";
    else
        cout<<"No";
    cout<<line;
}