#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a,t;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        deque<int>q;
        q.clear();
        for(int i=1; i<=n; i++)
        {
            cin>>a;
            if(a<q.front()||q.empty())q.push_front(a);
            else q.push_back(a);
        }
        for(int i=1; i<=n; i++)cout<<q.front()<<" ",q.pop_front();
    }
    return 0;
}
