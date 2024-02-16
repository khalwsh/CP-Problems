#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    string s;
    cin>>s;
    for(int i=0;i<(int)s.size();i++)
    {
        if(i>=3)
            cout<<0;
        else
            cout<<s[i];
    }
}