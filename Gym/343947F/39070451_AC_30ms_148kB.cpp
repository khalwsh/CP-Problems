#include<iostream>
#include<map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    getline(cin,s);
    map<char,int>mp;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
            continue;
        mp[s[i]]++;
    }
    string s2;
    getline(cin,s2);
    bool fail=0;
    for(int i=0;i<s2.size();i++)
    {
        if(s2[i]==' ')
            continue;
        if(mp[s2[i]]==0)
        {
            fail=1;
            break;
        }
        else
            mp[s2[i]]--;
    }
    if(fail)
        cout<<"NO";
    else
        cout<<"YES";

}
