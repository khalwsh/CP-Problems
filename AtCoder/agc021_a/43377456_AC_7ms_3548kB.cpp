#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    string s;
    cin >> s;
    int n =(int) s.size();
    int ans = (n - 1) * 9 + (s[0] - '0');
    for (int i = 1; i < n; ++i) {
        if (s[i] != '9') {
            --ans;
            break;
        }
    }
    cout<<ans; 
}