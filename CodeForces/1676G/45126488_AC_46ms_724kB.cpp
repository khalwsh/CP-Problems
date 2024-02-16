#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
void dfs(int i,int p,vector<int>&cnt1,vector<int>&cnt2,string &s,vector<int>adj[]){
    if(s[i]=='W')cnt2[i]++;
    else cnt1[i]++;
    for(auto x:adj[i]){
        if(x==p)continue;
        dfs(x,i,cnt1,cnt2,s,adj);
        cnt1[i] += cnt1[x];
        cnt2[i] += cnt2[x];
    }
}int main() {
    khaled
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>adj[n];
        for(int i=1;i<n;i++)
        {
            int x;
            cin>>x;
            x--;
            adj[x].emplace_back(i);
            adj[i].emplace_back(x);
        }
        string s;
        cin>>s;
        vector<int>v1(n),v2(n);
        dfs(0,-1,v1,v2,s,adj);
        int counter=0;
        for(int i=0;i<n;i++)
        {
            if(v1[i]==v2[i])
                counter++;
            //cout<<vp[i].first<<" "<<vp[i].second<<line;
        }
        cout<<counter<<line;
    }
}