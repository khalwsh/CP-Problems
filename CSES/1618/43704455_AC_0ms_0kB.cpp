#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    long long res=0;
    long long n;
    cin>>n;
    for(long long i=5;i<=n;i*=5)
    {
        res+=n/i;
    }
    cout<<res;

}