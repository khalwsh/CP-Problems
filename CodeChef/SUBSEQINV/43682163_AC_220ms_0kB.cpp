#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod=998244353;
long long fast_power(long long base,long long power)
{
    if(power==0)
        return 1;
    long long res= fast_power(base,power/2)%mod;
    res=(res%mod)*(res%mod);
    res%=mod;
    if(power&1)
        return ((res%mod)*(base%mod))%mod;
    else
        return res%mod;
}
int main() {
    khaled
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(auto &val:v)
            cin>>val;
        set<int>s;
        int my_max=v[0];
        for(int i=0;i<n;i++)
        {
            if(my_max>v[i])
                s.insert(v[i]);
            my_max=max(v[i],my_max);
        }
        int my_min=v[n-1];
        for(int i=n-1;i>=0;i--)
        {
            if(my_min<v[i])
                s.insert(v[i]);
            my_min=min(my_min,v[i]);
        }
        long long to_cal=n-(int)s.size();
        if(to_cal==n)
            cout<<((fast_power(2ll,to_cal)-1)%mod+mod)%mod<<line;
        else
            cout<<fast_power(2,to_cal)<<line;
    }
}