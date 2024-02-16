#include<bits/stdc++.h>
#define endl '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<int>v;
bool prime(int n);
int main()
{
    khaled
    int n;
    cin>>n;
    for(int i=2; i<=n; i++)
    {
        if(prime(i))
            v.emplace_back(i);
    }

    vector<int>res;
    int z=v.size();
    for(int j=1; j<=n; j++)
    {
        int c=0;
        for(int i=0; i<z; i++)
        {
            if(j%v[i]==0)
                c++;
        }
        if(c==2)
             res.emplace_back(1);
    }
    cout<<(int)res.size();
//hi
}
bool prime(int n)
{
    for(int i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
