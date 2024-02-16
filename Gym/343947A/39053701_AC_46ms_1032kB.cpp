#include<iostream>
#include<map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<char,int>mp;
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    int pos=0;
    for(int i=0; i<n; i++)
        mp[s[i]]++;
    for(int i=97; i<=122; i++)
    {
        if(k>=mp[char(i)])
        {
          k-=mp[(char)i];
          mp[(char)i]=0;
        }

        else
        {
            pos=i;
            break;
        }
    }
    int z=mp[(char)pos];
    mp[(char)pos]-=k;
    for(int i=0; i<n; i++)
    {
        if(mp[s[i]]==0)
            continue;
        else if(s[i]==(char)pos&&z>mp[(char)pos])
            z--;
        else
            cout<<s[i];

    }

}
