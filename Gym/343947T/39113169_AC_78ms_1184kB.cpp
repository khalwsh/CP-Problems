#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int>v(n);
    vector<long long>sum(n);
    map<long long,long long>mp;
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
        if(i==0)
            sum[0]=v[0];
        else
            sum[i]=sum[i-1]+v[i];
    }
    int m;
    cin>>m;
    int z;
    int l;
    while(m--)
    {
        cin>>l;
        z=upper_bound(sum.begin(),sum.end()-1,l-.5)-sum.begin();
       // if(z==n)
            //cout<<n;
        //else
            cout<<z+1;
        cout<<endl;
    }
}
