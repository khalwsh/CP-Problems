#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int n;
    cin>>n;
    vector<vector<char>>v(n,vector<char>(n));
    for(auto &val:v)
        for(auto &i:val)
            cin>>i;
    bool fail=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]=='-')
                continue;
            if(v[i][j]=='W'&&v[j][i]!='L')
                fail=true;
            else if(v[i][j]=='D'&&v[j][i]!='D')
                fail=true;
            else if(v[i][j]=='L'&&v[j][i]!='W')
                fail=true;
        }
    }
    if(fail)
        cout<<"incorrect";
    else
        cout<<"correct";


}
