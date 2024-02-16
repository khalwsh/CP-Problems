#include <iostream>
using namespace std;
int main()
{
    int t;
    ::freopen("window.in","rt",stdin);

    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        cout<<a*b<<endl;
    }
    return 0;
}