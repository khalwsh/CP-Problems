#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
istream&operator>>(istream&in,pair<long long,long long>&p)
{
    in>>p.first>>p.second;
    return in;
}
long double cal_dist(long long x,long long y,long long a,long long b)
{
    return (long double)sqrt((double)(abs(x-a)*abs(x-a))+(double)(abs(y-b)*abs(y-b)));
}
int main() {
    khaled
    int n;
    long double d;
    cin>>n>>d;
    queue<pair<long long,long long>>q;
    vector<pair<long long,long long>>vp(n);
    for(auto &val:vp)cin>>val;
    q.push(vp[0]);
    vector<bool>vis(n,false);
    vis[0]=true;
    while(!q.empty())
    {
        long long cur_x=q.front().first;
        long long cur_y=q.front().second;
        q.pop();
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(cal_dist(cur_x,cur_y,vp[i].first,vp[i].second)<=d)
                {
                    vis[i]=true,q.push(vp[i]);
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(vis[i])
            cout<<"Yes";
        else
            cout<<"No";
        cout<<line;
    }
}