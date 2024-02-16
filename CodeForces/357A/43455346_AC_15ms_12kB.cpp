#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int  m;
    cin>>m;
    vector<int>v(m);
    for(auto &val:v)cin>>val;
    int x,y;
    cin>>x>>y;
    long long res=-1;
    for(int i=0;i<=m;i++)
    {
        long long counter_small=0,counter_big=0;
        for(int l=0;l<m;l++)
        {
            if(l+1>=i)counter_big+=v[l];
            else
                counter_small+=v[l];
        }
        if(counter_big>=x&&counter_big<=y&&counter_small>=x&&counter_small<=y)
        {
            res=i;
            break;
        }
    }
    cout<<((res==-1)?0:res)<<line;
}