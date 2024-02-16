#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>v(n);
    for(auto &val:v)
        cin>>val;
    sort(v.begin(),v.end());
    int pointer=-1;
    for(int i=0;i<n;i++)
    {
        if(v[i]<pointer+1)continue;
        if(v[i]==pointer+1)pointer++;
        else
            break;
    }
    cout<<min(pointer+1,k);


}
