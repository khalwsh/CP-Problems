#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int n;
    int k;
    cin>>n>>k;
    vector<long long>v;
    for(int i=0;i<n;i++)
    {
        long long x;
        cin>>x;
        v.emplace_back(x);
    }
    set<long long>s;
    s.insert(0);
    int counter=0;
    while(counter<k)
    {
        long long x=*s.begin();
        s.erase(s.begin());
        counter++;
        for(auto &val:v)
            s.insert(val+x);
    }
    cout<<*s.begin()<<line;
}