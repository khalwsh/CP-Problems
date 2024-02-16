#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
long long n,x[100001],y[100001];
bool check(int a,int b){
    vector<int>v;
    for(int i=0;i<n;i++){
        if(i==a||i==b)
            continue;
        if((y[a]-y[b])*(x[a]-x[i])!=(y[a]-y[i])*(x[a]-x[b])){
            v.push_back(i);
        }
    }
    if(v.size()<=2)
        return true;
    for(int i=2;i<v.size();i++){
        if((y[v[0]]-y[v[1]])*(x[v[0]]-x[v[i]])!=(y[v[0]]-y[v[i]])*(x[v[0]]-x[v[1]])){
            return false;
        }
    }
    return true;
}
int main()
{
    khaled
    cin>>n;
    for(int i=0;i<n;i++)cin>>x[i]>>y[i];
    if(n<=4)cout<<"YES";
    else{
        bool flag=check(0,1)||check(0,2)||check(1,2);
        if(flag)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<line;
    }
    return 0;
}