#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    long long a,b;
    cin>>a>>b;
    if((a+b)&1^1)
        cout<<(a+b)/2;
    else
    {
        cout<<"IMPOSSIBLE";
    }

}