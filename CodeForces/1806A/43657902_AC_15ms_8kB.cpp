#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int t;
    cin>>t;
    while(t--)
        {
            long long a,b,c,d;
            cin>>a>>b>>c>>d;
            long long res=0;
            if(d<b)
                cout<<-1<<line;
            else
            {
                res+=d-b;
                a+=d-b;
                if(a<c)
                    cout<<-1<<line;
                else
                {
                    cout<<a-c+res<<line;
                }
            }
        }
}