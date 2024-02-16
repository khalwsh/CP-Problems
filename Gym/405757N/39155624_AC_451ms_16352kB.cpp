#include<iostream>
#include<stack>
#include<map>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string s;
    stack<string>ss;
    map<string,int>mp;
    for(int i=0; i<n; i++)
    {
        cin>>s;
        ss.push(s);
        mp[s]++;
    }
    while(!ss.empty())
    {
        if(mp[ss.top()]!=0)
        {
            cout<<ss.top()<<endl;
            if(mp[ss.top()]>1)
                mp[ss.top()]=0;
        }
        ss.pop();
    }



}
