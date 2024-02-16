#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        if(n%3==0)
        {
            cout<<n/3<<" "<<(n/3)<<endl;
            continue;
        }
        else
        {
            int j=n/3;
            if(n-3*j==1)
                cout<<n/3+1<<" "<<n/3<<endl;
            else
                cout<<n/3<<" "<<n/3+1<<endl;

        }
    }
}
