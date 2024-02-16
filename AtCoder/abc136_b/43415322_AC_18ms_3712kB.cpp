#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool odd(int i)
{
    string s= to_string(i);
    return s.size()&1;
}
int main() {
    khaled
    int n;
    cin>>n;
    int counter=0;
    for(int i=1;i<=n;i++)
    {
        if(odd(i))
            counter++;
    }
    cout<<counter<<line;
}