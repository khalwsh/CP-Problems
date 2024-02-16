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
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &val:v)
        cin>>val;
    bool found=false;
    if(sorted(v))
        found=true;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            swap(v[i],v[j]);
            if(sorted(v))
            {
                found=true;break;
            }
            swap(v[i],v[j]);
        }
        if(found)
            break;
    }
    if(found)
        cout<<"YES";
    else
        cout<<"NO";

}