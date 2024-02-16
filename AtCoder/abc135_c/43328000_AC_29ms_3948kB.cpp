#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool sorted(vector<int>&v)
{
    int n=(int)v.size();
    for(int i=0;i<n-1;i++)
    {
        if(v[i+1]<v[i])return false;

    }
    return true;
}
int main() {
    khaled
    int n;cin>>n;
    vector<int>v(n+1) , b(n);
    for (int i = 0; i < n+1; ++i) {
        cin>>v[i];
    }
    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin>>b[i];
        if(b[i] >= v[i])
        {
            cnt += v[i];
            b[i] -= v[i];
            v[i] = 0;

        }
        else
        {
            cnt += b[i];
            v[i] -= b[i];
            b[i] = 0;
        }
        if(b[i] >= v[i+1])
        {
            cnt += v[i+1];
            b[i] -= v[i+1];
            v[i+1] = 0;

        }
        else
        {
            cnt += b[i];
            v[i+1] -= b[i];
            b[i] = 0;
        }
    }
    cout<<cnt<<endl;

}