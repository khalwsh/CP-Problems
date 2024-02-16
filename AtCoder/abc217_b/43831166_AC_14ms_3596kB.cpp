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
    map<string,int>mp;
    string s1;
    string s2;
    string s3;
    cin>>s1>>s2>>s3;
    mp[s1]++;
    mp[s2]++;
    mp[s3]++;
    for(auto &val:{"ABC","AGC","ARC","AHC"})
        if(mp.find(val)==mp.end())
        {
            cout<<val<<line;
        }
}
