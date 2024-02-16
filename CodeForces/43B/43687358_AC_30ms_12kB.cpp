#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    string s1;
    string s2;
    getline(cin,s1);
    //cin.ignore();
    getline(cin,s2);
    map<char,int>mp1,mp2;
    for(auto &val:s1)
    {
        if(isblank(val))continue;
        mp1[val]++;
    }
    for(auto &val:s2) {
        if (isblank(val))continue;
        mp2[val]++;
    }
    for(auto &val:mp2)
    {
        if(val.second>mp1[val.first])
        {
            cout<<"NO";
            exit(0);
        }
    }
    cout<<"YES";
}