#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool sorted(vector<int>&v)
{
    int n=(int)v.size();
    for(int i=0;i+1<n;i++)
    {
        if(v[i+1]<v[i])
            return false;
    }
    return true;
}
int main() {
    khaled
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        for(auto &val:a)cin>>val;
        for(auto &val:b)cin>>val;
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++)
        {
            int pos=i;
            int my_min=a[i];
            for(int j=i+1;j<n;j++)
            {
                if(a[j]<my_min)
                {
                    pos=j;
                    my_min=a[j];
                }
            }
            if(pos!=i)
                swap(a[i],a[pos]),vp.emplace_back(i,pos);
        }
        for(auto &val:vp)
        {
            swap(b[val.first],b[val.second]);
        }

        vector<pair<int,int>>vp2;
        for(int i=0;i<n;i++)
        {
            int pos=i;
            int my_min=b[i];
            for(int j=i+1;j<n;j++)
            {
                if(b[j]<my_min)
                {
                    pos=j;
                    my_min=b[j];
                }
            }
            if(pos!=i)
                swap(b[i],b[pos]),vp2.emplace_back(i,pos);
        }
        for(auto &val:vp2)
        {
            swap(a[val.first],a[val.second]);
        }
        if(sorted(a)&&sorted(b))
        {
            cout<<vp.size()+vp2.size();
            cout<<line;
            for(auto &val:vp)
                cout<<1+val.first<<" "<<1+val.second<<line;
            for(auto &val:vp2)
                cout<<1+val.first<<" "<<1+val.second<<line;
        }
        else
            cout<<-1<<line;
    }
}