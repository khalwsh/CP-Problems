#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=2e5+5;
//https://w...content-available-to-author-only...e.com/P8F43A

int main() {
    FAST
  int n,k,m;
    cin>>n>>k>>m;
    vector<string>s(n);
    vector<int>cost(n);
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
        cin>>cost[i];
    int q;
    for(int i=0;i<k;i++)
    {
        cin>>q;
        int temp[q],mn=1e9;
        for(int j=0;j<q;j++)
        {
            cin>>temp[j];
            temp[j]--;
            mn= min(mn,cost[temp[j]]);
        }
        for(int j=0;j<q;j++)
        {
            cost[temp[j]]=mn;
        }
    }
    map<string,int>ncost;
    for(int i=0;i<n;i++)
    {
        ncost[s[i]]=cost[i];
    }
    long long ans=0;
    string t;
    for(int i=0;i<m;i++)
    {
        cin>>t;
        ans+=ncost[t];
    }
    cout<< ans;
    return 0;
}
