#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &val:v)cin>>val;
    map<int,int>mp;
    int my_max=0;
    for(int i=0;i<n;i++){
        mp[(v[i]-i-1+n)%n]++;
        mp[(v[i]+1-i-1+n)%n]++;
        mp[(v[i]+2-i-1+n)%n]++;
        my_max=max({my_max,mp[(v[i]-i-1+n)%n],mp[(v[i]+1-i-1+n)%n],mp[(v[i]+2-i-1+n)%n]});
    }
    cout<<my_max<<endl;


}
