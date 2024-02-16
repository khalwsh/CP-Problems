#include<iostream>
#include<vector>
#include<set>
#include<map>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int>v(n);
    set<int>s;
    set<int>::iterator it=s.begin();
    map<int,int>mp;
    int map_max=-1;
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
        it=s.emplace_hint(it,v[i]);
        mp[v[i]]++;
        map_max=max(map_max,mp[v[i]]);

    }
    while(map_max--)
    {
        for(auto &val:s)
        {
            cout<<val<<" ";
            mp[val]--;
        }
        s.clear();
        set<int>::iterator iiit=s.begin();
        for(auto &val:mp)
        {
            if(val.second==0)
                continue;
            iiit=s.emplace_hint(iiit,val.first);
        }
        cout<<endl;
    }

}
