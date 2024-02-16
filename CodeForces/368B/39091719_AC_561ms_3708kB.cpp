#include<bits/stdc++.h>
using namespace std;
int n,m,l;
set<int> s;
int main()
{
    cin>>n>>m;
    int a[n+1];
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=n; i>0; i--)
    {
        s.insert(a[i]);
        a[i]=s.size();
    }
    for(int i=1; i<=m; i++)
        cin>>l,cout<<a[l]<<endl;
}
