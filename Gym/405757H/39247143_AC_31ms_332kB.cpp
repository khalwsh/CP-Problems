#include<iostream>
#include<set>
#include<vector>
#include<map>
#define endl '\n'
using namespace std;
int main()
{
    int q;
    cin>>q;
    vector<string>v(q);
    map<string,string>mp;
    string s;
    set<string>ss;
    set<string>::iterator it=ss.begin();
    for(int i=0; i<q; i++)
    {
        cin>>v[i];
        cin>>s;
        it=ss.emplace_hint(it,s);
        auto iit=ss.find(v[i]);
        if(iit!=ss.end())
        {
            for(auto &val:mp)
            {
                if(val.second==*iit)
                {
                    val.second=s;
                    mp.erase(*iit);
                    break;
                }
            }
            ss.erase(*iit);
        }
        else
            mp[v[i]]=s;
    }
    cout<<mp.size()<<endl;
    for(auto &val:mp)
        {
            cout<<val.first<<" "<<val.second<<endl;
        }
}
