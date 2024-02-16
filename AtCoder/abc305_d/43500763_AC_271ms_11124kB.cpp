#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void add(vector<pair<int,int>>v[],int first,int second,int dist)
{
    v[first].emplace_back(second,dist);
    v[second].emplace_back(first,dist);
}
long long dikstra(int start,int dist,vector<pair<int,int>>v[])
{
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>>pq;
    vector<int>distance(7,INT_MAX);
    distance[start]=0;
    pq.push({0,start});
    while(!pq.empty())
    {
        int node=(int)pq.top().second;
        long long cost=pq.top().first;
        pq.pop();
        if(cost!=distance[node])continue;
        for(auto &val:v[node])
        {
            if(distance[val.first]>=cost+val.second)
            {
                distance[val.first]=cost+val.second;
                pq.push({distance[val.first],val.first});
            }
        }
    }
    return distance[dist];
}
int main() {
    khaled
    int n;
    cin>>n;
    vector<long long>v(n);
    for(auto &val:v)
        cin>>val;
    int q;
    cin>>q;
    vector<long long>sleep(n+1);
    sleep[0]=0;
    set<pair<int,int>>time_sleep;
    for(int i=1;i<n;i+=2)
    {
        sleep[i+1]=v[i+1]-v[i];
        time_sleep.insert(make_pair(i,i+1));
    }
    for(int i=1;i<=n;i++)
        sleep[i]+=sleep[i-1];
    while(q--)
    {
        long long l,r;
        cin>>l>>r;
        int first= lower_bound(v.begin(),v.end(),l)-v.begin();
        int second= lower_bound(v.begin(),v.end(),r)-v.begin();
        long long res=0;
        if(time_sleep.find(make_pair(first-1,first))!=time_sleep.end())
        {
            if(time_sleep.find(make_pair(second-1,second))!=time_sleep.end())
            {
                 res+=v[first]-l;
                 res+=r-v[second-1];
                 res+=sleep[second-1]-sleep[first];
                 res=min(res,r-l);
                 res=max(0ll,res);
            }
            else
            {
                res+=v[first]-l;
                res+=sleep[second-1]-sleep[first];
                res=min(res,r-l);
                res=max(0ll,res);
            }
        }
        else
        {
            if(time_sleep.find(make_pair(second-1,second))!=time_sleep.end())
            {
                res+=r-v[second-1];
                res+=sleep[second-1]-sleep[first];
                res=min(res,r-l);
                res=max(0ll,res);
            }
            else
            {
                res+=sleep[second-1]-sleep[first];
                res=min(res,r-l);
                res=max(0ll,res);
            }
        }
        cout<<res<<line;
    }
}