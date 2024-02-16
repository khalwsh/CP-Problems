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
        int res=0;
        sort(v.begin(),v.end());
        int sum=0;
        vector<int>tot;
        for(int i=0;i<n;i++){
            if(v[i]+sum<=300)
                sum+=v[i],res++,tot.emplace_back(sum);
            else
                break;
        }
        sum=0;
        for(auto &val:tot)sum+=val;
        cout<<res<<" "<<sum<<line;
    }
}