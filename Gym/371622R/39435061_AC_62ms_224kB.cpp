#include<iostream>
#include<bitset>
#include<vector>
#include<algorithm>
#include<cmath>
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    string s;
    int k;
    while(t--)
    {
       cin>>s;
       cin>>k;
       vector<string>v;
       int z=pow(2,s.size());
       for(int i=0;i<z;i++)
       {
           string temp="";
           bitset<64>bs(i);
           for(int j=0;j<64;j++)
           {
               if(bs[j]&1)
                temp+=s[j];
           }
           v.push_back(temp);
       }
       sort(v.begin(),v.end());
       cout<<v[k-1]<<endl;

    }
}
