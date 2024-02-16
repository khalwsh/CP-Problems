#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
signed main() {
    khaled
    long long n,k;
    cin>>n>>k;
    long long left=2,right=k;
    long long res=-1;
    if(n==1) {
        cout << 0;
        exit(0);
    }
    while(left<=right)
    {
        long long mid=left+(right-left)/2;
        long long comp=(k*(k+1))/2-(mid*(mid-1))/2-(k-mid);
        if(comp>=n)
            res=(k-mid+1),left=mid+1;
        else
            right=mid-1;
    }
    cout<<res<<line;
}