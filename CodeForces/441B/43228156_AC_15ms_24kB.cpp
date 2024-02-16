#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int n,k;
    cin >> n >> k;
    int a,b;
    vector<int> v(3005);
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        v[a]+=b;
    }
    int sum =0;
    for (int i = 1; i <= 3003; ++i) {
        int tmp = k;
        int my_min = min(tmp,v[i-1]);
        tmp-=my_min;
        v[i-1]-=my_min;
        sum+=my_min;//collect last day
        my_min = min(tmp,v[i]);
        v[i]-=my_min;
        sum+=my_min;//collect cur day
    }
    cout << sum << line;

}