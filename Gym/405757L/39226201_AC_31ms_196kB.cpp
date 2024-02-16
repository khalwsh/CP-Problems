#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=2e5+5;
 
int main() {
    FAST
    int n;
    cin>>n;
    set<long long >s;
    s.insert(1);
    n--;
    while (n--){
        auto it = s.begin();
        long long x = *it;
        s.erase(it);
        s.insert(x*2);
        s.insert(x*3);
        s.insert(x*5);
    }
    cout <<  *s.begin();
 
    return 0;
}