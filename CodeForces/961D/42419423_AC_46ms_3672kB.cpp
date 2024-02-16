#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
int n;
vector<pair<long long,long long>>vp;
bool check(long long a,long long b){
   vector<long long>remain;
   for(long long i=0;i<n;i++)
   {
       if(i==a||i==b)
           continue;
       if((vp[b].second-vp[a].second)*(vp[i].first-vp[a].first)!=(vp[b].first-vp[a].first)*(vp[i].second-vp[a].second))
           remain.emplace_back(i);
   }
   if(remain.size()<=2)
       return true;
   b=remain[1];
   a=remain[0];
   for(int i=2;i<remain.size();i++)
   {
       if((vp[b].second-vp[a].second)*(vp[remain[i]].first-vp[a].first)!=(vp[b].first-vp[a].first)*(vp[remain[i]].second-vp[a].second))
           return false;
   }
   return true;
}
int main()
{
    khaled
    cin>>n;
    vp.resize(n);
    for(auto &[l,r]:vp)
        cin>>l>>r;
    if(n<=4)cout<<"YES";
    else{
        bool flag=check(n-1,n-2)||check(n-1,n-3)||check(n-2,n-3);
        if(flag)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<line;
    }
    return 0;
}