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
    long long n;
    cin>>n;
    if(n<=9)
        cout<<n;
    else
    {
        string s=to_string(n);
        long long value=0;
        bool f= all_of(s.begin()+1,s.end(),comp);
        reverse(s.begin(),s.end());
        for(int i=0;i<(int)s.size()-1;i++)
            value+=9;
        if(f)value+=s.back()-'0';
        else 
            value+=s.back()-'0'-1;
        cout<<value;
    }
}