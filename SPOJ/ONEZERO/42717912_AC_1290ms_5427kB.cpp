#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
string smallest_multiple(int n) {
    queue<string> q;
    vector<bool> visited(n, false);
    q.emplace("1");
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        int remainder = 0;
        for (char c : s) {
            remainder = (remainder * 10 + (c - '0')) % n;
        }
        if (remainder == 0) {
            return s;
        }
        if (!visited[remainder]) {
            visited[remainder] = true;
            q.push(s + "0");
            q.push(s + "1");
        }
    }
    return "";
}
int main() {
    khaled
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<smallest_multiple(n)<<line;
    }
}