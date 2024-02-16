#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
bool valid(int i,int j,int n,int m)
{
    return i>=0&&j>=0&&i<n&&j<m;
}
void mark(int i,int j,vector<vector<pair<char,char>>>&matrix,int n,int m,vector<vector<int>>&vis)
{
    if(!valid(i,j,n,m)||vis[i][j])
        return;
  vis[i][j]=true;
  char one=matrix[i][j].first;
  char two=matrix[i][j].second;
  if(one=='R')
  {
      if(valid(i,j+1,n,m)&&!vis[i][j+1])
          mark(i,j+1,matrix,n,m,vis);
  }else if(one=='L')
  {
      if(valid(i,j-1,n,m)&&!vis[i][j-1])
          mark(i,j-1,matrix,n,m,vis);
  }
  if(two=='U')
  {
        if(valid(i-1,j,n,m)&&!vis[i-1][j])
            mark(i-1,j,matrix,n,m,vis);
  }else if(two=='D')
  {
        if(valid(i+1,j,n,m)&&!vis[1+i][j])
            mark(i+1,j,matrix,n,m,vis);
  }
}
bool flood_fill(vector<vector<pair<char,char>>>&matrix,int n,int m)
{
    bool work=true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            vector<vector<int>>vis(n,vector<int>(m));
            mark(i,j,matrix,n,m,vis);
            for(auto &val:vis)
            {
                for(auto &k:val) {
                    //cout<<k<<" ";
                    if (k == 0) {
                        work = false;
                        break;
                    }
                }
                //cout<<line;
                if(!work)
                    break;
            }
            if(!work)
                break;
        }
        if(!work)
            break;
    }
    if(!work)
        return false;
    return true;
}
int main() {
    khaled
    int n;
    int m;
    cin>>n>>m;
    vector<int>adj[n];
    string s1,s2;
    cin>>s1>>s2;
    vector<vector<pair<char,char>>>matrix(n,vector<pair<char,char>>(m));
    for(int i=0;i<n;i++) {
        if (s1[i] == '>') {
            for (int j = 0; j < m; j++)
                matrix[i][j].first = 'R';
        } else
        {
            for (int j = 0; j < m; j++)
                matrix[i][j].first = 'L';
        }
    }
    for(int i=0;i<m;i++)
    {
        if(s2[i]=='^')
        {
            for (int j = 0; j < n; j++)
                matrix[j][i].second = 'U';
        }
        else {
            for (int j = 0; j < n; j++)
                matrix[j][i].second = 'D';
        }
    }
    bool res=flood_fill(matrix,n,m);
    if(res)
        cout<<"YES";
    else
        cout<<"NO";
}