#include<bits/stdc++.h>
using namespace std;
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define line '\n'
signed main() {
    khaled
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(auto &val:v)cin>>val;
        vector<int>adj[20001];
        for(int i=0;i<n;i++){
            adj[v[i]].emplace_back(i);
        }
        vector<int>vis(20001,false);
        int res=0;
        for(int i=1;i<=20000;i++){
            if(vis[i]||adj[i].empty())continue;
            vis[i]=true;
            int cur=adj[i].front();
            int cnt=1;
            for(int j=i+1;j<=20000;j++){
                if(adj[j].empty())break;
                auto it= lower_bound(adj[j].begin(),adj[j].end(),cur);
                if(it==adj[j].end())break;
                cnt++,cur=*it;
            }
            res=max(res,cnt);
        }
        cout<<res<<line;
    }
}