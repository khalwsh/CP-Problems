#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
int BFS(vector<vector<char>>&grid,int row_start,int col_start,bool open_door,int n,int m)
{
    queue<pair<bool,pair<int,int>>>q;//current state of door,,row,,col
    q.push({open_door,{row_start,col_start}});
    int dist=0;
    vector<vector<vector<bool>>>vis((2),vector<vector<bool>>(n,vector<bool>(m)));
    vis[open_door][row_start][col_start]=true;
    int dx[]{0,0,1,-1};
    int dy[]{1,-1,0,0};
    while(!q.empty())
    {
        int sz=(int)q.size();
        while(sz--)
        {
            bool door_state=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            bool cur_door_state=door_state;
            if(grid[row][col]=='O')cur_door_state=true;
            if(grid[row][col]=='C')cur_door_state=false;
            q.pop();
            if(row==0||row==n-1||col==0||col==m-1)return dist+1;
            for(int l=0;l<4;l++)
            {
               int cur_row=row+dx[l];
               int cur_col=col+dy[l];
               if(grid[cur_row][cur_col]!='W'&&!vis[cur_door_state][cur_row][cur_col]&&!(cur_door_state==false&&grid[cur_row][cur_col]=='D'))
               {
                   q.push({cur_door_state,{cur_row,cur_col}});
                   vis[cur_door_state][cur_row][cur_col]=true;
               }
            }
        }
        dist++;
    }
    return -1;
}
int main() {
    khaled
    while(true)
    {
        int n,m;
        cin>>n>>m;
        if(n==-1)
            break;
        vector<vector<char>>grid(n,vector<char>(m));
        int row_start=0,col_start=0;
        bool open_door=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]=='H') {
                    row_start = i;
                    col_start = j;
                }
            }
        }
        cout<<BFS(grid,row_start,col_start,open_door,n,m)<<line;
    }
}