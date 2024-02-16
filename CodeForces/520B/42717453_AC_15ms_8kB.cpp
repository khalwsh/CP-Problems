#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
long long solve(long long n,long long m)
{
    if(n>=m)return n-m;
    return (m&1^1)?solve(n,m/2)+1:solve(n,m+1)+1;
}
int main() {
    khaled
    long long n,m;
    cin>>n>>m;
    cout<<solve(n,m)<<line;
}