#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    //cin>>t;
    string s;
    while(cin>>s)
    {
       // cin>>s;
        int z=s.size();
        deque<char>dq;
        bool flag_up=0,flag_back=0;
        string temp="";
        for(int i=0; i<z; i++)
        {
            if(s[i]=='['&&flag_up==0)
            {
                flag_up=1,flag_back=0;
                continue;
            }
 
            else if(s[i]==']'||(s[i]=='['&&flag_up==1))
            {
                reverse(temp.begin(),temp.end());
                for(int j=0; j<temp.size(); j++)
                {
                    dq.push_front(temp[j]);
                }
                if(s[i]=='['&&flag_up==1)
                {
                    temp="";
                    continue;
                }
                flag_back=1,flag_up=0;
                temp="";
 
            }
            if(i==z-1&&flag_up==1)
            {
                temp+=s[z-1];
                reverse(temp.begin(),temp.end());
                for(int j=0; j<temp.size(); j++)
                {
                    dq.push_front(temp[j]);
                }
            }
 
            if(flag_back==0&&flag_up==0)
            {
                dq.push_back(s[i]);
            }
            else if(flag_up)
            {
                temp+=s[i];
                //dq.push_front(s[i]);
            }
            else if(flag_back)
                dq.push_back(s[i]);
        }
        for(auto it=dq.begin(); it!=dq.end(); it++)
        {
            if(*it!=']'&&*it!='[')
                cout<<*it;
            else
                continue;
        }
        cout<<endl;
    }
 
 
}