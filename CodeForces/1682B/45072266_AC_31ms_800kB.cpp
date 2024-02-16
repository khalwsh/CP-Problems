#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
int main() {
    khaled
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(auto &val:v)
            cin>>val;
        int j=0;
        int pos=0;
        int min1=INT_MAX;
        for(int i=0;i<n;i++,j++)
        {
            if(j!=v[i]) {
                pos = i;
                min1&=v[i];
            }
        }
        if(v[0]!=0)
            cout<<0<<line;
        else
            cout<<min1<<line;
    }

}