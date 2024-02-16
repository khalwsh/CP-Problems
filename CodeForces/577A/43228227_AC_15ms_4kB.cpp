#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int n;
    cin>>n;
    long long x;
    cin>>x;
    long long res=0;
    for(int i=1;i<=n;i++)
    {
        if(x%i==0)
        {
            if(x%i==0&&x/i<=n)res++;
        }
    }
    cout<<res<<line;

}