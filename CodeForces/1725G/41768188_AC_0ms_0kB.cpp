#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
if(n==1)
n++;
else 
n++,n++;
if(n%3==0)
cout<<n/3*4<<endl;
else if(n%3==1)
cout<<n/3*4+1<<endl;
else 
cout<<n/3*4+3<<endl;
}