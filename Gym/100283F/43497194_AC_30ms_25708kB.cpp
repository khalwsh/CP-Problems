#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
long long binary(long long n)
{
    long long left=1;
    long long right=5e5;
    long long counter=0;
    while(left<=right) {
        long long mid = left + (right - left) / 2;
        long long cal = mid * mid + (mid-1)*(mid)*(2 * (mid-1) + 1) / 6;
        if (cal >= n)
        {
            counter=mid;
            right=mid-1;
        }
        else
            left=mid+1;
    }
    return counter;
}
long long work(long long res,long long counter,long long n)
{
    long long left=1;
    long long right=counter;
    long long now_res=0;
    while(left<=right)
    {
        long long mid=left+(right-left)/2;
        long long cal=mid*(mid+1)/2;
        if(cal+res>=n)
        {
            now_res=mid;
            right=mid-1;
        }
        else
            left=mid+1;
    }
    return now_res;
}
long long work2(long long res,long long counter,long long n)
{
    long long left=1;
    long long right=counter-1;
    long long now_res=INT_MAX;
    while(left<=right)
    {
        long long mid=left+(right-left)/2;
        long long cal=counter*(counter+1)/2-mid*(mid-1)/2;
        if(cal+res>=n)
        {
            now_res=min(now_res,counter-mid);
            left=mid+1;
        }
        else
            right=mid-1;
    }
    return now_res;
}
typedef long long ll;
vector<ll> v;
ll sum(ll n){return n * (n + 1) / 2;}
void gen(){
    ll i = 1 , j = 1;
    v.emplace_back(0);
    v.emplace_back(1);
    while(v.back() <= ll(1e18)){
        ll n = v.size();
        v.emplace_back(v.back() + sum(n) + sum(n - 1));
    }
}
int main() {
    khaled
    int t;
    freopen("army.in","rt",stdin);
    gen();
    //freopen("army.in","rt",stdin);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        long long n;
        cin>>n;
        long long res=1;
        long long counter=1;
        counter=binary(n);
        counter--;
        long long final_count=counter*counter;
        res=counter*(counter+1)*(2*counter+1)/6;
        counter++;
        if(counter*(counter+1)/2+res>=n)
        {
            cout<<"Case "<<i<<": "<<final_count+work(res,counter,n);
        }
        else
        {
            ll l = lower_bound(v.begin() , v.end() , n) - v.begin() - 1;
            ll ans = l * l;
            n -= v[l];
            l++;
            if(sum(l) < n){
                ans += l;
                n -= sum(l);
                // l - 1 , l - 2 , .. 1
                ll l1 = 1 , r1 = l - 1 , mid;
                while(l1 < r1){
                    mid = l1 + (r1 - l1) / 2;
                    if(sum(l - 1) - sum(l - 1 - mid) >= n) r1 = mid;
                    else l1 = mid + 1;
                }
                ans += l1;
            }else{
                // 1 , 2 , 3 , .. , l
                ll l1 = 1 , r1 = l , mid;
                while(l1 < r1){
                    mid = l1 + (r1 - l1) / 2;
                    if(sum(mid) >= n) r1 = mid;
                    else l1 = mid + 1;
                }
                ans += l1;
            }
            cout<<"Case "<<i<<": "<< ans;
        }
        if(i!=t)
            cout<<line;
    }
    //1 1 2 1 1 2 3 2 1
}