#include<bits/stdc++.h>
using namespace std;
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define line '\n'
bool valid(int i,int j,int n,int m){
    return i>=0&&i<n&&j>=0&&j<m;
}
signed main() {
    khaled
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<string>>v(n,vector<string>(m));
        for(auto &val:v)for(auto &i:val)cin>>i;
        bool flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]!="p")continue;
                //check line
                if(valid(i,j+1,n,m)&&v[i][j+1]=="i"&&valid(i,j+2,n,m)&&v[i][j+2]=="e")flag=true;
                if(valid(i,j-1,n,m)&&v[i][j-1]=="i"&&valid(i,j-2,n,m)&&v[i][j-2]=="e")flag=true;
                //check col
                if(valid(i+1,j,n,m)&&v[i+1][j]=="i"&&valid(i+2,j,n,m)&&v[i+2][j]=="e")flag=true;
                if(valid(i-1,j,n,m)&&v[i-1][j]=="i"&&valid(i-2,j,n,m)&&v[i-2][j]=="e")flag=true;
                //check diag
                if(valid(i+1,j+1,n,m)&&v[i+1][j+1]=="i"&&valid(i+2,j+2,n,m)&&v[i+2][j+2]=="e")flag=true;
                if(valid(i-1,j-1,n,m)&&v[i-1][j-1]=="i"&&valid(i-2,j-2,n,m)&&v[i-2][j-2]=="e")flag=true;
                if(valid(i-1,j+1,n,m)&&v[i-1][j+1]=="i"&&valid(i-2,j+2,n,m)&&v[i-2][j+2]=="e")flag=true;
                if(valid(i+1,j-1,n,m)&&v[i+1][j-1]=="i"&&valid(i+2,j-2,n,m)&&v[i+2][j-2]=="e")flag=true;
            }
        }
        cout<<(flag?"Cutie Pie!":"Sorry Man")<<line;
    }
}