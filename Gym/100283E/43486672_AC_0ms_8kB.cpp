#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int t;
    ::freopen("ghanophobia.in","rt",stdin);
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        int value1,value2;
        cin>>value1;
        char ch;
        cin>>ch;
        cin>>value2;
        if(value1==6&&value2==1)
        {
            cout<<"Case"<<" "<<k<<": "<<"PENALTIES";
        }
        else if(value1+1>value2+6)
        {
            cout<<"Case"<<" "<<k<<": "<<"YES";
        }
        else if(value1+1==value2+6)
        {
            if(value2>1)
                cout<<"Case"<<" "<<k<<": "<<"NO";
            else
                cout<<"Case"<<" "<<k<<": "<<"YES";
        }
        else
            cout<<"Case"<<" "<<k<<": "<<"NO";
        if(k!=t)
        cout<<line;

    }
}