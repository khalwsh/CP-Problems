#include<iostream>
#include<vector>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int n,q;
    int x;
    while(t--)
    {
        cin>>n>>q;
        vector<int>v(n);
        while(q--)
        {
            cin>>x;
            for(int i=x-1;i<n;i+=x)
                v[i]=1;
        }
        for(auto &val:v)
            cout<<val<<" ";
        cout<<endl;
    }
}
