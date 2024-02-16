#include<iostream>
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
    set<string>s;
    set<string>::iterator it=s.begin();
    string b;
    map<string,int>mp;
    string k;
    int z;
    while(n--)
    {
        z=s.size();
        cin>>b;
        k=b;
        mp[k]++;
        it=s.emplace_hint(it,b);
        if(z==s.size())
        {
           b+=to_string(mp[k]-1);
           it=s.emplace_hint(it,b);
           cout<<k<<mp[k]-1<<endl;
        }
        else
        {
            cout<<"OK"<<endl;
        }
    }
}
