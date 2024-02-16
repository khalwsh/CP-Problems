#include<iostream>
#include<vector>
#include<set>
#include<map>
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int n;
    string s1,s2;
    bool flag=0;
    while(t--)
    {
        flag=1;
        cin>>n;
        cin>>s1>>s2;
        map<char,multiset<int>>mpms;
        vector<int>id(n);
        for(int i=0; i<n; i++)
        {
            cin>>id[i];
            mpms[s1[i]].insert(id[i]);
        }
        for(int i=0; i<n; i++)
        {
            auto it=mpms[s2[i]].find(id[i]);

            if(it!=mpms[s2[i]].end())
            {
                mpms[s2[i]].erase(mpms[s2[i]].find(id[i]));
            }

            else
                flag=0;
        }
        if(flag)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<endl;
    }
}
