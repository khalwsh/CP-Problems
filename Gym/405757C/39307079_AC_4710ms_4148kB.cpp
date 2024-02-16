#include <iostream>
#include <map>
#include <set>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        int ids[n];
        bool check = false;
        map<char,multiset<int>>mp;
        for(auto &it:ids)
            cin>>it;
        for(int i=0; i<n; i++)
            mp[s[i]].emplace(ids[i]);
        for(int i=0; i<n; i++)
        {
            if(mp[t[i]].count(ids[i]))
            {
                auto it = mp[t[i]].find(ids[i]);
                mp[t[i]].erase(it);
            }
            else
            {
                check = true;
                break;
            }
        }
        cout<<((check)?"NO\n":"YES\n");

    }
    return 0;
}
