#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool valid(int i,int j,int n,int m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const int&mod){return ((x%y)*(y%mod))%mod;}
long long add(long long x,long long y,const int&mod){return (((x%mod)+(y%mod))+mod)%mod;}
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
/*--------------------------------------------------------------------------------------------------------------------*/
class dsu{
public:
    vector<int>parent;
    vector<int>siz;
public:
    dsu()=default;
    dsu(int n)
    {
        //intializing the parent and rank
        parent.resize(n+1);
        siz.resize(n+1,1);
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }
    int find_parent(int child)
    {
        //this function find the ultimate parent of certain child and make a update the parent
        if(parent[child]==child)
            return child;
        return parent[child]=find_parent(parent[child]);
    }
    void union_by_size(int a,int b)
    {
        int pa= find_parent(a);
        int pb= find_parent(b);
        if(pa==pb)return;
        if(siz[pa]>=siz[pb])
            siz[pa]+=siz[pb],parent[pb]=pa;
        else if(siz[pb]>siz[pa])
            siz[pb]+=siz[pa],parent[pa]=pb;
    }
    bool same_component(int a,int b)
    {
        return find_parent(a)==find_parent(b);
    }
};
signed main() {
    khaled
    int n;
    cin>>n;
    dsu d(n);
    int counter_throw=0;
    vector<pair<int,int>>throw_edge;
    vector<int>ultimate_parents;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        if(d.find_parent(a)==d.find_parent(b))
        {
            counter_throw++,throw_edge.emplace_back(a+1,b+1);

        }
        d.union_by_size(a,b);
    }
    int counter_need=0;
    for(int i=0;i<n;i++)
    {
        if(d.find_parent(i)==i)
            ultimate_parents.emplace_back(i);
    }
    if(ultimate_parents.size()==1)
        cout<<"0";
    else
    {
        cout<<ultimate_parents.size()-1<<line;
        for(int i=1;i<ultimate_parents.size();i++)
        {
            cout<<throw_edge[i-1].first<<" "<<throw_edge[i-1].second<<" "<<ultimate_parents[0]+1<<" "<<ultimate_parents[i]+1<<line;
        }
    }
}