#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long>v(n);
    vector<long long>sum(n);
    set<long long>s;
    set<long long>::iterator it=s.begin();
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
        if(i==0)
            sum[i]=v[i];
        else
            sum[i]=sum[i-1]+v[i];
        it=s.emplace_hint(it,sum[i]);
    }
    //1 4 5 6 10
    //1 3 1 1 4
    //22 33 1 55
    //22 55 56
    long long sum_last=0;
    long long my_max=-2147483648;
    for(int i=n-1; i>0; i--)
    {
        sum_last+=v[i];
        if(sum_last>=sum[i])
            break;
        auto it=s.find(sum_last);
        if(it!=s.end())
        {
            my_max=max(*it,my_max);
        }
    }
    if(my_max==-2147483648)
        cout<<0;
    else
        cout<<my_max;
}
