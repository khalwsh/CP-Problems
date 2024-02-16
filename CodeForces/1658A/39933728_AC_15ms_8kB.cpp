#include<bits/stdc++.h>
#define endl '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    khaled
    string s;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        int c=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='0'&&s[i+1]=='0')
                c+=2;
            else if(s[i]=='0'&&s[i+1]=='1'&&s[i+2]=='0')
                c++;
        }
        cout<<c;
        cout<<endl;
    }


}
