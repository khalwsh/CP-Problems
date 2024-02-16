#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool comp(char v)
{
    return v=='9';
}
int main() {
    khaled
    int n; cin >> n;
    priority_queue<long long, vector<long long>, greater<> > pq;
    long long sum = 0;
    for(int i = 1;i <= n;i++){
        long long x; cin >> x;
        sum += x;
        pq.push(x);
        while(sum< 0){
            sum -= pq.top();
            pq.pop();
        }
    }
    cout << (int) pq.size();

}