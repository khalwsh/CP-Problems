#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
bool valid(int i,int j,int n,int m)
{
    return i>=0&&i<n&&j>=0&&j<m;
}
pair<int,int> multisourceBFS(vector<vector<char>>&grid,queue<pair<int,int>>&q,vector<vector<bool>>&vis,int n,int m)
{
    int dx[]{0,0,1,-1};
    int dy[]{1,-1,0,0};
    pair<int,int>last;
    while(!q.empty())
    {
        int sz=(int)q.size();
        while(sz--)
        {
            int row=q.front().first;
            int col=q.front().second;
            last=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int cur_row=row+dx[i];
                int cur_col=col+dy[i];
                if(valid(cur_row,cur_col,n,m)&&!vis[cur_row][cur_col])
                    vis[cur_row][cur_col]=true,q.push({cur_row,cur_col});
            }
        }
    }
    return last;
}
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p)
{
    return os <<p.first+1 <<" "<< p.second+1 <<line;
}
int main() {
    khaled
    int n,m;
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(auto &val:grid)
    {
        for(auto &i:val)
            i='.';
    }
    int k;
    cin>>k;
    queue<pair<int,int>>q;
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    while(k--)
    {
        int x,y;
        cin>>x>>y;x--,y--;
        q.emplace(x,y);//multisource BFS
        vis[x][y]=true;
    }
    cout<<multisourceBFS(grid,q,vis,n,m);
}