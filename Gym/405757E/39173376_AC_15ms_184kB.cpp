#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
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
    vector<string>v(n);
    int my_max=0;
    string s_max;
    multimap<int,string>mp;
    pair<int,string>vp[n];
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i].size()>my_max)
        {
            my_max=v[i].size();
            s_max=v[i];
        }
        vp[i].first=v[i].size();
        vp[i].second=v[i];
        //mp[v[i].size()]=v[i];
        mp.insert({v[i].size(),v[i]});
    }
    sort(vp,vp+n);
    bool fail=0;
    /*for(int i=0;i<n;i++)
    {
        if(s_max.find(v[i])==-1)
        {
            fail=1;
            break;
        }
    }*/
    for(int i=0;i<n-1;i++)
    {
        if((int)(vp[i+1].second.find(vp[i].second))==-1)
        {
            fail=1;
            break;
        }
    }
    if(fail)
        cout<<"NO";
    else
    {
        cout<<"YES";
        cout<<endl;
        for(auto &val:mp)
            cout<<val.second<<endl;
    }

}
