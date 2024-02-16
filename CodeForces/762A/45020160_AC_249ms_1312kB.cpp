#include<set>
#include<iostream>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    long long n,k,d;
    set<long long> a;
    cin>>n>>k;
    for(d=1;d*d<=n;d++)
        if(n%d==0)
            a.insert({d, n/d});
    if(k<=a.size())
        cout<<*next(a.begin(),k-1);
    else
        cout<<-1;
}