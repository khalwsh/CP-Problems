#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
long long fast_power(long long base,long long power,const int mod)
{
    if(power==0)
        return 1;
    long long res= fast_power(base,power/2,mod)%mod;
    res=((res%mod)*(res%mod))%mod;
    if(power&1)
        return ((res%mod)*(base%mod))%mod;
    else
        return res%mod;
}
int main() {
    khaled
    int t;
    cin>>t;
    while(t--) {
        long long n;
        long long k;
        cin >> n >> k;
        bitset<64> bb(k);
        long long res = 0;
        const int mod = 1e9 + 7;
        for (int i = 0; i < 64; i++) {
            if(bb[i]==1)
                 res = ((res % mod) + ((long long) (fast_power(n, i,mod)) % mod)) % mod;
        }
        cout << res << line;
    }
}