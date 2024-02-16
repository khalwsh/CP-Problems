#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod=1e9+7;
int add(int a,int b){
    return ((a%mod)+(b%mod))%mod;
}
signed main() {
    khaled
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &val:v)
        cin>>val;
    int left=0,right=0;
    set<int>s;
    int res=0;
    while(right!=n)
    {
        int sz=(int)s.size();
        s.insert(v[right]);
        if(sz==(int)s.size())
        {
            //cout<<v[left]<<" ";
            while(v[left]!=v[right])
               s.erase(v[left]),left++;
            s.erase(v[left]);left++;
            s.insert(v[right]);
            //cout<<left<<" "<<right<<line;
        }
        res=max(res,right-left+1);right++;
    }
    cout<<res<<line;
}