#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool valid(int i,int j,int n,int m)
{
    return i>=0&&i<n&&j>=0&&j<m;
}
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
    int m;
    cin>>n>>m;
    map<int,int>mp;
    set<int>s;
    for(int i=1;i<=n;i++)s.insert(i);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        int c;
        cin>>c;
        auto it=s.lower_bound(a);
        auto it2=s.upper_bound(b);
        for(auto t=it;t!=it2;)
        {
            if(*t!=c&&!mp.count(*t)) {
                mp[*t] = c;
                auto itt=t;
                t++;
                s.erase(*itt);
            }else
                t++;
        }

    }
    for(int i=0;i<n;i++)
        cout<<mp[i+1]<<" ";
}