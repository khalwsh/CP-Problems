#include<iostream>
#include<vector>
#include<map>
#include<set>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    set<int>s;
    set<int>::iterator it=s.begin();
    int a;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=n-1;i>=0;i--)
    {
        s.insert(v[i]);
        v[i]=(int)s.size();
    }
    int l;
    while(m--)
    {
      cin>>l;
      l--;
      cout<<v[l]<<endl;
    }
}
