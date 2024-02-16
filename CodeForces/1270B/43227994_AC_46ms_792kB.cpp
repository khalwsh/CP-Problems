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
        vector<int>v(n);
        for(auto &val:v)
            cin>>val;
        int first=-1,second=-1;
        for(int i=0;i+1<n;i++)
        {
            if(abs(v[i]-v[i+1])>=2)
            {
                first=i;
                second=i+1;
                break;
            }
        }
        if(first==second)
            cout<<"NO"<<line;
        else
            cout<<"YES"<<line<<first+1<<" "<<second+1<<line;
    }
}