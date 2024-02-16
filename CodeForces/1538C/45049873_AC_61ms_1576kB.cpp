#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
int binary_search_min(vector<int>&v,int fixed,int n,int l)
{
    int left=fixed;
    int right=n-1;
    int res=-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(v[mid]+v[fixed]>=l)
        {
            right=mid-1;
            res=mid;
        }
        else
            left=mid+1;
    }
    if(res==fixed)
    {
        if(res+1<n&&v[fixed]+v[res+1]>=l)
            return res+1;
        else
            return -1;
    }
    return res;
}
int binary_search_max(vector<int>&v,int fixed,int n,int r)
{
    int left=fixed;
    int right=n-1;
    int res=-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(v[mid]+v[fixed]<=r)
        {
            res=mid;
            left=mid+1;
        }
        else
            right=mid-1;
    }
    if(res==fixed)
        return -1;
    return res;
}
signed main() {
    khaled
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int l,r;
        cin>>l>>r;
        vector<int>v(n);
        long long summation=0;
        for(auto &val:v)
            cin>>val;
        sort(v.begin(),v.end());
        int counter=0;
        for(int i=0;i<n;i++)
        {
            int bin1= binary_search_min(v,i,n,l);
            int bin2= binary_search_max(v,i,n,r);
            if(bin1==-1||bin2==-1)
                continue;
            counter+=bin2-bin1+1;
        }
        cout<<counter<<line;
    }
}