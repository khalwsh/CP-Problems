#include<bits/stdc++.h>
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main() {
    khaled
    long long n;
    cin >> n;
    set<long long>s;
    for (long long i = 1; i * i <= n; i++)
    {
        if(n%i==0)
            s.insert(i),s.insert(n/i);
    }
    for(auto &val:s)
        cout<<val<<line;
}