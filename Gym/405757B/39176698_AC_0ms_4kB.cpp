#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
using namespace std;
int main()
{

    int n,q;
    cin>>n>>q;//n elements q queries
    vector<string>v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    string s;
    int x;
    while(q--)
    {
        cin>>x;
        if(q!=0&&x==1)
        cin.ignore();
        getline(cin,s);
        if(x==1)
        {
            bool fail=0;
            int khaled;
            vector<string>::iterator iiit=v.begin();
            for(auto iit=v.begin();iit!=v.end();iit++)
            {
                if(*iit==s)
                {
                    fail=0;
                    iiit=iit;
                    break;
                }
                else
                    fail=1;
            }
            if(fail)
                cout<<"Not found"<<endl;
            else
            {

                v.erase((iiit+khaled));
            }

        }
        else if(x==2)
        {
            int z=v.size();
            if(z==0)
                cout<<0<<endl;
            else
            {
                for(auto &val:v)
                    cout<<val<<" ";
                cout<<endl;
            }


        }
        else
        {
            int z=v.size();
            if(z==0)
                cout<<0<<endl;
            else
            {
                //reverse(v.begin(),v.end());
                vector<string>::reverse_iterator iiiit=v.rbegin();
                for(;iiiit!=v.rend();iiiit++)
                {
                    cout<<*iiiit<<" ";
                }
                cout<<endl;
                //reverse(v.begin(),v.end());
            }
        }
    }
}
