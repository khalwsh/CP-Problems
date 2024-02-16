#include<iostream>
#include<vector>
#include<map>
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int n;
    string s;
    int x;
    while(t--)
    {
      cin>>n;
      vector<map<char,int>>vmp(n);
      vector<string>vs(n);
      for(int i=0;i<n;i++)
      {
        cin>>vs[i];
        for(int j=0;j<vs[i].size();j++)
        {
            if(vs[i][j]>122||vs[i][j]<97)
            {
                vmp[i][vs[i][j]]++;
            }
        }

      }
      map<int,char>mp;
      for(int i=97;i<=122;i++)
      {
          cin>>x;
          mp[x]=(char)i;
      }
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<vs[i].size();j++)
        {
            if(vs[i][j]>122||vs[i][j]<97)
            {
               auto it=mp.find(vmp[i][vs[i][j]]);
               cout<<it->second;
            }
            else
                cout<<vs[i][j];
        }
        cout<<endl;

      }

    }
}
