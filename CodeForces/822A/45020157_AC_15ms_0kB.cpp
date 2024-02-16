#include<bits/stdc++.h>
#define line '\n'
#define khaled ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
using namespace std;
long long factorial(long long a);
int main()
{
    khaled
    long long a,b;
    cin>>a>>b;
    long long my_min=min(a,b);
    cout<<factorial(my_min);
}
long long factorial(long long a)
{
    if(a==0||a==1)
        return 1;
    else
        return a* factorial(a-1);
}