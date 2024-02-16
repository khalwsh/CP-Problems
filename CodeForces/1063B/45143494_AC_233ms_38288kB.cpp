#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool valid(int i,int j,int n,int m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const int&mod){return ((x%y)*(y%mod))%mod;}
long long add(long long x,long long y,const int&mod){return (((x%mod)+(y%mod))+mod)%mod;}
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
/*--------------------------------------------------------------------------------------------------------------------*/

signed main() {
    khaled
    int n;
    int m;
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    int start1,start2,x,y;
    cin>>start1>>start2>>x>>y;
    start1--,start2--;
    for(auto &val:v)for(auto &i:val)cin>>i;
    queue<pair<pair<int,int>,pair<int,int>>>q;//how many left,how many right,row col
    q.push({{x,y},{start1,start2}});
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    vis[start1][start2]=true;
    vector<vector<int>>right(n,vector<int>(m,0)),left(n,vector<int>(m,0));
    right[start1][start2]=y;
    left[start1][start2]=x;
    while(!q.empty())
    {
        int how_many_left=q.front().first.first;
        int how_many_right=q.front().first.second;
        int row=q.front().second.first;
        int col=q.front().second.second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(i==2&&how_many_right<=0)continue;
            if(i==3&&how_many_left<=0)continue;
            int cur_row=row+dx[i];
            int cur_col=col+dy[i];
            if(valid(cur_row,cur_col,n,m)&&!vis[cur_row][cur_col]&&v[cur_row][cur_col]!='*')
            {
                if(i==2)
                    how_many_right--;
                if(i==3)
                    how_many_left--;
                vis[cur_row][cur_col]=true;
                q.push({{how_many_left,how_many_right},{cur_row,cur_col}});
                left[cur_row][cur_col]=how_many_left,right[cur_row][cur_col]=how_many_right;
                //cout<<cur_row<<" "<<cur_col<<" "<<how_many_left<<" "<<how_many_right<<line;
                if(i==2)
                    how_many_right++;
                if(i==3)
                    how_many_left++;
            }
            else if(valid(cur_row,cur_col,n,m)&&v[cur_row][cur_col]!='*'&&(how_many_left>left[cur_row][cur_col]||how_many_right>right[cur_row][cur_col]))
            {
                if(i==2)
                    how_many_right--;
                if(i==3)
                    how_many_left--;
                vis[cur_row][cur_col]=true;
                q.push({{how_many_left,how_many_right},{cur_row,cur_col}});
                left[cur_row][cur_col]=how_many_left,right[cur_row][cur_col]=how_many_right;
                //cout<<cur_row<<" "<<cur_col<<" "<<how_many_left<<" "<<how_many_right<<line;
                if(i==2)
                    how_many_right++;
                if(i==3)
                    how_many_left++;
            }
        }
    }
    int counter=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]&&v[i][j]!='*')
                counter++;
        }
    }
    cout<<counter<<line;
}