#include<bits/stdc++.h>
#define line '\n'
#define khaled ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
using namespace std;
int main() {
    khaled
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    set<int>s;
    auto it=s.begin();
    vector<int>v_res;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        for(int j=2;j*j<=v[i];j++)
        {
            while(v[i]%j==0)
            {
                it=s.emplace_hint(it,j);
                v[i]/=j;
            }
        }
        if(v[i]!=1)
            it= s.emplace_hint(it,v[i]);
    }
    v_res.emplace_back(1);
    bool flag;
    for(int i=2;i<=m;i++)
    {
        flag=false;
        for(auto &val:s)
        {
            if(i%val==0)
            {
                flag=true;
                break;
            }
        }
        if(!flag)
            v_res.emplace_back(i);
    }
    cout<<v_res.size();
    cout<<line;
    for(auto &val:v_res)
    {
        cout<<val<<" ";
    }
}