#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
long double dikstra(vector<pair<int,pair<long double,long double>>>adj[],int starting,int target,int n)
{
    vector<long double>temprature(n,1e9);
    temprature[starting]=0;
    priority_queue<pair<long double,int>,vector<pair<long double,int>>,greater<pair<long double,int>>>pq;
    pq.push({0,starting});
    while(!pq.empty())
    {
        int node=pq.top().second;
        long double temp=pq.top().first;
        pq.pop();
        if(temprature[node]!=temp)
            continue;
        if(node==target)
            return temp;
        for(auto &val:adj[node])
        {
            if(temprature[val.first]>max(temp,val.second.first))
            {
                temprature[val.first]=max(temp,val.second.first);
                pq.push({temprature[val.first],val.first});
            }
        }
    }
    return -1;
}
long double dikstra2(vector<pair<int,pair<long double,long double>>>adj[],int starting,int target,int n,vector<int>&parent,long double target_temp)
{
   vector<long double>dist(n,1e9);
   dist[starting]=0;
   priority_queue<pair<long double,int>,vector<pair<long double,int>>,greater<pair<long double,int>>>pq;
   pq.push({0,starting});
   while(!pq.empty())
   {
       int node=pq.top().second;
       long double cost=pq.top().first;
       pq.pop();
       if(cost!=dist[node])
           continue;
       if(node==target)
           return cost;
       for(auto &val:adj[node])
       {
           if(target_temp>=val.second.first&&dist[val.first]>cost+val.second.second)
           {
               dist[val.first]=cost+val.second.second;
               pq.push({dist[val.first],val.first});
               parent[val.first]=node;
           }
       }
   }
   return -1;
}
int main() {
    khaled
    int n;
    int t=1;
    while(cin>>n)
    {
        int m;
        cin>>m;
        int starting,target;
        cin>>starting>>target;starting--,target--;
        vector<pair<int,pair<long double,long double>>>adj[n];
        while(m--)
        {
            int from,to;
            long double R,D;
            cin>>from>>to>>R>>D;
            from--,to--;
            adj[from].emplace_back(to, make_pair(R,D));
            adj[to].emplace_back(from, make_pair(R,D));
        }
        long double min_temp=dikstra(adj,starting,target,n);
        vector<int>parent(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        long double min_dist=dikstra2(adj,starting,target,n,parent,min_temp);
        vector<int>path;
        int x=target;
        //cout<<starting<<flush;
        while(x!=starting)
        {
            path.emplace_back(x);
            x=parent[x];//cout<<x;
        }
        path.emplace_back(starting);
        reverse(path.begin(),path.end());
        for(auto &val:path) {
            cout << val + 1;
            if (val != target)
                cout << " ";
        }
        cout<<line;
        cout<<fixed << setprecision(1)<<min_dist<<" "<<min_temp<<line;
    }
}