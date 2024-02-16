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
 string s;
 cin>>s;
 string temp;
 bool flag=false;
 string t;
 for(int i=0;i<s.size();i++)
 {
     if(!flag)
         t+=s[i];
     if(flag)
         temp+=s[i];
     flag=(s[i]=='.');
 }
 t.pop_back();
 stringstream sss;
 sss<<temp;
 int y;
 sss>>y;
 sss<<t;
 int x;
 sss>>x;
 if(y>=0&&y<=2)
     cout<<t<<"-";
 else if(y>=3&&y<=6)
 {
     cout<<t;
 }
 else
     cout<<t<<"+";
}
