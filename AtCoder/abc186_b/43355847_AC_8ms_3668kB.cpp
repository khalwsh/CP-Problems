#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int n;
    int m;
    cin>>n>>m;
    vector<vector<long long>>v(n,vector<long long>(m));
    for(auto &val:v)for(auto &i:val)cin>>i;
    long long my_min=INT_MAX;
    for(auto &val:v)
    {
        my_min=min(my_min,*min_element(val.begin(),val.end()));
    }
    long long res=0;
    for(auto &val:v)
    {
        for(auto &i:val)res+=i-my_min;
    }
    cout<<res;


}