#include<bits/stdc++.h>
#define endl '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
    khaled
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        int sum_first=0,sum_second=0;
        int i=0,j=n-1;
        int c=0,res=0;
        while(true)
        {
            if(sum_first<=sum_second)
            {
                sum_first+=v[i];
                i++;c++;
            }
            else if(sum_first>sum_second)
            {
                sum_second+=v[j];
                j--;c++;
            }
            if(sum_first==sum_second)
                res=c;
            if(i>j)
                break;
               // cout<<sum_first<<" "<<sum_second<<endl;

        }
        cout<<res;
        cout<<endl;


    }
}