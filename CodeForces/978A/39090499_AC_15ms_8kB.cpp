#include<iostream>
#define endl "\n"
#include<vector>
#include<map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long l,r;
    int n;
    cin>>n;
    vector<int>v(n);
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        mp[v[i]]++;
    }
    cout<<mp.size()<<endl;
    for(int i=0;i<n;i++)
    {
        if(mp[v[i]]==1)
            cout<<v[i]<<" ";
        else
        {
            mp[v[i]]--;
        }
    }

}
