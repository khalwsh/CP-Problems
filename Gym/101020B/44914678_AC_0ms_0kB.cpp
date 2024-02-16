#include<bits/stdc++.h>
using namespace std;
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define line '\n'
signed main() {
    khaled
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if((a*b)&1){
            cout<<"Hussain";
        }else{
            cout<<"Hasan";
        }
        cout<<line;
    }
}