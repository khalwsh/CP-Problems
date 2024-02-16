#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int n;
    int k;
    cin>>n;
    cin>>k;
    vector<int>v(n);
    for(auto &val:v)
        cin>>val;
    vector<int>prefix(n);
    prefix[0]=v[0];
    for(int i=1;i<n;i++)
        prefix[i]=prefix[i-1]+v[i];
    long long max=prefix[k-1];
    long long index=1;
    for(int i=k;i<n;i++)
    {
        if(prefix[i]-prefix[i-k]<max)
        {
            max=prefix[i]-prefix[i-k];
            //cout<<max<<line;
            index=i-k+2;
        }
    }
    cout<<index<<line;
}