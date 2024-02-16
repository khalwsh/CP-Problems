#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main()
{
    int n;//number of the socks pairs
    cin>>n;
    vector<int>v(2*n);
    map<int,int>mp;
    int my_max=-1;
    int c=0;
    for(int i=0;i<2*n;i++)
    {
        cin>>v[i];
        mp[v[i]]++;
        if(mp[v[i]]==2)
            c--;
        else
            c++;
        my_max=max(my_max,c);
    }
    cout<<my_max;
}
