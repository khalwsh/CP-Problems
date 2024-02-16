#include<bits/stdc++.h>
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    sort(s.begin(),s.end());
    vector<string>v;
    do {
        v.emplace_back(s);
    }while(next_permutation(s.begin(),s.end()));
    sort(v.begin(),v.end());
    cout<<v[k-1];
}
