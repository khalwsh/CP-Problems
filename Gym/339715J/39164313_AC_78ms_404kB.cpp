#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;//number of the shops;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    int q;
    cin>>q;
    int x;
    int z;
    while(q--)
    {
      cin>>x;
      z=upper_bound(v.begin(),v.end(),x)-v.begin();
      cout<<z;
      cout<<endl;
    }



}
