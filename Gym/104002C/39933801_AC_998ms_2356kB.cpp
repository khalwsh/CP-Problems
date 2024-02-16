#include<bits/stdc++.h>
#define endl '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
    khaled
    int n,k;
    cin>>n>>k;
    vector<pair<long long,long long>>vp(n);
    vector<long long >v_product(n);
    long long max_sum=0;
    int m=0;
    for(int i=0;i<n;i++)
    {
        cin>>vp[i].first>>vp[i].second;
        v_product[i]=vp[i].first*vp[i].second;
        if(i+1>=k)
        {
            int temp_sum=0;
            for(int j=m ;j<m+k;j++)
            {
               temp_sum+=v_product[j];
            }
            if(temp_sum>max_sum)
                max_sum=temp_sum;
            m++;
        }
    }
    cout<<max_sum;

}
