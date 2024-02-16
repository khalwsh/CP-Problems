#include<iostream>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long l,r;
    cin>>l>>r;
    if(r-l>=4)
        cout<<2;
    else if(r%2==0||l%2==0)
        cout<<2;
    else
        cout<<l;
}
