#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin>>n;
    vector<long long>v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    vector<long long>sum(n);
    vector<long long>sum2(n);
    sum[0]=v[0];
    for(int i=1; i<n; i++)
        sum[i]=sum[i-1]+v[i];
    sort(v.begin(),v.end());
    sum2[0]=v[0];
    for(int i=1; i<n; i++)
        sum2[i]=sum2[i-1]+v[i];
    int m;
    cin>>m;
    int type,l,r;
    while(m--)
    {
        cin>>type>>l>>r;
        if(type==1)
        {
          (l==1)?cout<<sum[r-1]:cout<<sum[r-1]-sum[l-2];
        }
        if(type==2)
        {
          (l==1)?cout<<sum2[r-1]:cout<<sum2[r-1]-sum2[l-2];
        }
        cout<<endl;

    }
}
