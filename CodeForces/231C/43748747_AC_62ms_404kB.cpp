#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int n,k;cin >> n >> k;
    vector<int>v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int l = 1,r = n,ans,mn;
    while (l <= r){
        int mid = (l+r)/2;
        bool ok = false;
        int last = 0;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            if(i + 1 < mid){
                sum += v[i];
            }
            else{
                long long need = 1ll * v[i] * (mid - 1) - sum;
                if(need <= k){
                    mn = v[i];
                    ok = true;
                    break;
                }
                sum -= v[last++];
                sum += v[i];
            }
        }
        if(ok){
            ans = mid;
            l = mid + 1;
        }
        else  r = mid - 1;
    }
    cout << ans << ' ' << mn;
}

