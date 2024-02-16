#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool valid(int i,int j,int n,int m)
{
    return i>=0&&i<n&&j>=0&&j<m;
}
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
/*--------------------------------------------------------------------------------------------------------------------*/
signed main() {
    khaled
    int n;
    cin>>n;
    set<pair<string,string>>s;
    for(int i=0;i<n;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        s.insert(make_pair(s1,s2));
    }
    if(s.size()!=n)
        cout<<"Yes";
    else
        cout<<"No";
}
