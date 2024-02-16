#include<bits/stdc++.h>
using namespace std;
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define line '\n'
bool valid(int i,int j,int n,int m){
    return i>=0&&i<n&&j>=0&&j<m;
}
signed main() {
    khaled
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<(__gcd(a,b)==1?"GOOD":"NOT GOOD")<<line;
        // a*x+b*y=gcd(a,b)*c  x-->x*c/g
    }
}