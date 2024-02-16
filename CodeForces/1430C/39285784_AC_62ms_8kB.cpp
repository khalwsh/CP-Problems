#include<iostream>
#include<vector>
#define endl "\n"
#include<set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int n;
    while(t--)
    {
       cin>>n;
       cout<<2<<endl;
       int k=0;
       for(int j=n, i=n;i>1;i--)
       {
           k++;
           cout<<j<<" "<<i-1;
           cout<<endl;
           if(k<2);
           else
            j--;


       }
    }
}
