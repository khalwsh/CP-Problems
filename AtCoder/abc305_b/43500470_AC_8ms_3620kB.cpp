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
    vector<pair<int,int>>v[7];
    add(v,0,1,3);
    add(v,1,2,1);
    add(v,2,3,4);
    add(v,3,4,1);
    add(v,4,5,5);
    add(v,5,6,9);
    char first,second;
    cin>>first>>second;
    cout<<dikstra(first-'A',second-'A',v)<<line;
}