#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
bool valid(int i,int j,int n,int m)
{
    return i>=0&&i<n&&j>=0&&j<m;
}
int main() {
    khaled
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<char>>v(n,vector<char>(m));
        for(auto &val:v)
            for(auto &i:val)
                cin>>i;
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]=='1')
                {
                    vis[i][j]=true;
                    q.emplace(i,j);
                }
            }
        }
        vector<vector<int>>res(n,vector<int>(m));
        int dist=0;
        int dx[]{0,0,1,-1};
        int dy[]{1,-1,0,0};
        while(!q.empty()) {
            int sz = (int) q.size();
            while (sz--) {
                int row = q.front().first;
                int col = q.front().second;
                res[row][col] = dist;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int cur_row = row + dx[i];
                    int cur_col = col + dy[i];
                    if (valid(cur_row, cur_col, n, m) && !vis[cur_row][cur_col] && v[cur_row][cur_col] == '0')
                        q.emplace(cur_row, cur_col), vis[cur_row][cur_col] = true;
                }
            }
            dist++;
        }
        for(auto &val:res)
        {
            for(auto &i:val)
                cout<<i<<" ";
            cout<<line;
        }
    }
}