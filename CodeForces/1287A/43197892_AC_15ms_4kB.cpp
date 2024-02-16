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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int pos=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='A')
            {
                pos=i;
                break;
            }
        }
        if(pos==-1)
            cout<<0;
        else
        {
            int counter=0;
            int my_max_cons=0;
            for(int i=pos+1;i<n;i++)
            {
                if(s[i]=='P')
                    counter++;
                else
                    counter=0;
                my_max_cons=max(counter,my_max_cons);
            }
            cout<<my_max_cons;
        }
        cout<<line;
    }
}