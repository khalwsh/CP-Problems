#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int n;
    string s;
    cin>>n;
    while(n%7!=0)
    {
        s+='4';
        n-=4;
        if(n<0){
            cout<<-1; return 0;
        }
    }
    cout<<s;
    int temp=n/7;
    while(temp--)
        cout<<7;
}