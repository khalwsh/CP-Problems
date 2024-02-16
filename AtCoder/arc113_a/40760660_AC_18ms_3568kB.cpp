#include<bits/stdc++.h>
#define line '\n'
#define khaled ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
using namespace std;
int main() {
    khaled
    int k;
    cin>>k;
    long long int res=0;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i*j>k)
                break;
            for(int l=1;l<=k;l++)
            {
                if(i*j*l<=k)
                    res++;
                else
                {
                    break;
                }
            }
        }
    }
    cout<<res;

}