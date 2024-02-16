#include<bits/stdc++.h>
using namespace std;
char mp[10][1000];
int vis[10][1000];
int n,f;
void dfs(int x,int y) {
    if(y>=n) {
        f=1;
        return;
    }
    vis[x][y]=1;
    if(mp[x][y+1]!='.')return;
    if(x-1<=3&&x-1>=1&&!vis[x-1][y]&&mp[x-1][y+1]=='.'&&mp[x-1][y+2]=='.'&&mp[x-1][y+3]=='.')
        dfs(x-1,y+3);
    if(x+1<=3&&x+1>=1&&!vis[x+1][y]&&mp[x+1][y+1]=='.'&&mp[x+1][y+2]=='.'&&mp[x+1][y+3]=='.')
        dfs(x+1,y+3);
    if(!vis[x][y+3]&&mp[x][y+1]=='.'&&mp[x][y+2]=='.'&&mp[x][y+3]=='.')
        dfs(x,y+3);
    
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        f=0;
        int k,x,y;
        cin>>n>>k;
        for(int i=1; i<=3; i++) {
            for(int j=1; j<=n; j++) {
                cin>>mp[i][j];
                vis[i][j]=0;
                if(mp[i][j]=='s') {
                    x=i;
                    y=j;
                }
            }
        }
        for(int i=1; i<=3; i++)
            for(int j=n+1; j<=n+5; j++)
                mp[i][j]='.';


        dfs(x,y);
        if(f)
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
    }
}