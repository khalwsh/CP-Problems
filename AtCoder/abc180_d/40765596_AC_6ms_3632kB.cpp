#include<bits/stdc++.h>
#define line '\n'
#define khaled ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
using namespace std;
int main() {
    khaled
    unsigned long long x,y,a,b;
    cin>>x>>y>>a>>b;
    if(b+x<=x*a)
    {
        cout<<(y-x)/b-(((y-x)/b)*b+x==y);
    }
    else
    {
        unsigned long long res=0;
        unsigned long long temp=1;
        while(x<y)
        {
            temp=x;
            if(x*a<=temp)
            break;
            if(x*a>=y)
                break;
            if(x*a>x+b)
                break;
            else
                x*=a,res++;
        }
        if(b+x<y)
            res+=(y-x)/b-(((y-x)/b)*b+x==y);
        cout<<res;
    }
}