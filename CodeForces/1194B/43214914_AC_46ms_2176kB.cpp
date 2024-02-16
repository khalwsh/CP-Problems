#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int m;
        cin>>n>>m;
        vector<int>rows(n),col(m);
        vector<bool>intrect(n);
        vector<vector<char>>v(n,vector<char>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>v[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            int counter=0;
            for(int j=0;j<m;j++)
            {
                if(v[i][j]=='*')
                    counter++;
            }
            rows[i]=counter;
        }
        for(int j=0;j<m;j++)
        {
            int counter=0;
            for(int i=0;i<n;i++)
            {
                if(v[i][j]=='*')
                    counter++;
            }
            col[j]=counter;
        }
        int res=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                res=min(res,(int)(n-rows[i]+m-col[j]-(v[i][j]=='.')));

            }
        }
        cout<<res<<line;

    }
}