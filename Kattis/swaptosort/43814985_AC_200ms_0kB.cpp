#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool valid(int i,int j,int n,int m)
{
    return i>=0&&i<n&&j>=0&&j<m;
}
class dsu{
private:
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
    int m;
    cin>>n>>m;
    dsu d(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        d.union_by_size(a,b);
    }
    int left=0,right=n-1;
    bool work=true;
    while(left<right)
    {
        if(d.find_parent(left)!=d.find_parent(right))
        {
            work=false;
            break;
        }
        left++,right--;
    }
    cout<<(work?"YES":"NO");
}
