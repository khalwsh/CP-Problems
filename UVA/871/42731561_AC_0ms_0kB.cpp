#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
bool valid(int i,int j,int n,int m)
{
    return i>=0&&i<n&&j<m&&j>=0;
}
int BFS(vector<string>&grid,vector<vector<bool>>&vis,int i,int j,int n,int m)
{
    queue<pair<int,int>>q;
    q.emplace(i,j);
    vis[i][j]=true;
    int counter=0;
    counter++;
    int dx[]{0,0,1,-1,1,1,-1,-1};
    int dy[]{1,-1,0,0,1,-1,1,-1};
    while(!q.empty())
    {
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(int l=0;l<8;l++)
        {
            int cur_row=row+dx[l];
            int cur_col=col+dy[l];
            if(valid(cur_row,cur_col,n,m)&&!vis[cur_row][cur_col]&&grid[cur_row][cur_col]=='1')
            {
                vis[cur_row][cur_col]=true;
                q.emplace(cur_row,cur_col);
                counter++;
            }
        }
    }
    return counter;
}
int main() {
    khaled
    int t;
    cin>>t;
    string get_fucking_line;
    getline(cin,get_fucking_line);
    getline(cin,get_fucking_line);
    bool blank = false;
    while(t--)
    {
        vector<string>grid;
        string s;
        int n=0;
        vector<int>sizes;
        while(getline(cin,s)&&s!="")
        {
            grid.emplace_back(s);
            sizes.emplace_back((int)s.size());
            n++;
        }
        int m=(int)grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int my_max=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&grid[i][j]=='1')
                {
                     my_max=max(my_max,BFS(grid,vis,i,j,n,sizes[i]));
                }
            }
        }
        if(blank)cout<<line;
        blank=true;
        cout<<my_max<<line;
    }
}