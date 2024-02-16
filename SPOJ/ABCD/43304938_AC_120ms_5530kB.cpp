#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
khaled
int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = "";
    char last = 'Z';
    for (int i = 0; i < s.size(); i += 2) {
        int t = 2;
        while (t--) {
            for (int j = 'A'; j <= 'D'; j++) {
                if (s[i] != j && s[i + 1] != j && last != j) {
                    ans += (char)j;
                    last = j;
                    break;
                }
            }
        }
    }
    cout << ans ;
}