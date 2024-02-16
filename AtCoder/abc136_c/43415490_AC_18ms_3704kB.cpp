#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &val:v)
        cin>>val;
    bool work=true;
    for(int i=1;i<n;i++)
    {
        if(v[i-1]<v[i])
        {
            v[i]-=1;
        }
        if(v[i-1]>v[i]){
            work = false;
            break;
        }
    }
    cout<<(work?"Yes":"No");
}