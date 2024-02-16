#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int t;
    cin>>t;
    while(t--)
    {
        long long green,blue,red;
        cin>>red>>green>>blue;
        vector<long long>v(3);
        v[0]=red,v[1]=green,v[2]=blue;
        sort(v.begin(),v.end());
        if(v[0]+v[1]<v[2])
            cout<<v[0]+v[1];
        else{
            cout<<(red+blue+green)/2;
        }
        cout<<line;
    }
}