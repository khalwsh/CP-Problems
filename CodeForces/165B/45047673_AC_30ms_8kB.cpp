#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool can(long long mid,long long n,long long k)
{
    long long summation=0;
    int counter=0;
    while(summation<n)
    {
        summation+=(mid/pow(k,counter));
        if(pow(k,counter)>mid)
            break;
        counter++;
    }
    return summation>=n;
}
signed main() {
    khaled
    long long n,k;
    cin>>n>>k;
    long long left=1,right=n;
    while(left<=right)
    {
        long long mid=left+(right-left)/2;
        if(can(mid,n,k))
            right=mid-1;
        else
            left=mid+1;
    }
    cout<<right+1<<line;
}