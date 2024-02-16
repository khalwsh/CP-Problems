#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int n;
    int m;
    cin>>n>>m;
    vector<int>adj[n];
    map<pair<int,int>,bool>mp;
    bool fail=false;
    vector<int>indegree(n);
    while(m--)
    {
        int a,b;
        cin>>a>>b;a--,b--;
        if(!mp[make_pair(a,b)])
            adj[b].emplace_back(a),indegree[a]++;

        if(a==b)fail=true;
        mp[make_pair(a,b)]=true;
    }
    vector<int>topo(n);
    queue<int> q;
    for(int i=0;i<n;i++)
        if(indegree[i] == 0)
            q.push(i);
    int temp=n;
    while(!q.empty()){
        if(q.size() != 1) {
            fail = true;
            break;
        }
        int node = q.front();
        q.pop();
        topo[node] = temp--;
        for(auto &val : adj[node]) {
           indegree[val]--; if (indegree[val] == 0) q.push(val);
        }
    }
    if(topo.empty()||fail||topo.size()!=n)
        cout<<"No"<<line;
    else
    {
        cout<<"Yes";
        cout<<line;
        for(int i=0;i<n;i++)cout << topo[i] <<" ";
    }

}