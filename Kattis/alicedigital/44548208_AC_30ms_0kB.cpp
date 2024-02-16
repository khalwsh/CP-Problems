#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define int long long
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
signed main() {
    khaled
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<int>v(n);
        for(auto &val:v)cin>>val;
        vector<int>indexs;
        for(int i=0;i<n;i++){
            if(v[i]==m)indexs.emplace_back(i);
        }
        int res=0;
        for(auto &val:indexs){
            int sum=0;
            int temp=val;
            val++;
            sum+=v[val-1];
            while(val<n&&v[val]>m)sum+=v[val],val++;
            val=temp;
            val--;
            while(val>=0&&v[val]>m)sum+=v[val],val--;
            res=max(res,sum);
        }
        cout<<res<<line;
    }
}