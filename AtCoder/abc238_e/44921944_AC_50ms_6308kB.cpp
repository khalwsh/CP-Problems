#include<bits/stdc++.h>
using namespace std;
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define line '\n'
#define int long long
class dsu{
public:
    vector<int>parent,siz;
    dsu(int n){
        siz.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
    }
    int find(int a){
        return (a==parent[a]?a:parent[a]=find(parent[a]));
    }
    void merge(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b)return ;
        if(siz[a]>siz[b])swap(a,b);
        parent[a]=b;
        siz[b]+=siz[a];
    }
};
signed main() {
    khaled
    int n,m;
    cin>>n>>m;
    dsu d(n+1);
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        l--,r--;
        d.merge(l,r+1);
    }
    cout<<(d.find(0)==d.find(n)?"Yes":"No");
}