#include<iostream>
//qwertyuiopasdfghjkl;zxcvbnm,./

using namespace std;
int main()
{
    char ch;
    cin>>ch;
    string s;
    cin>>s;
    string res="";
    string orginal="qwertyuiopasdfghjkl;zxcvbnm,./";
    if(ch=='L')
    {
        for(int i=0; i<s.size(); i++)
        {
            for(int j=0; j<orginal.size(); j++)
            {
                if(s[i]==orginal[j])
                {
                    res+=orginal[j+1];
                }
            }
        }
    }
    else
    {
        for(int i=0; i<s.size(); i++)
        {
            for(int j=0; j<orginal.size(); j++)
            {
                if(s[i]==orginal[j])
                {
                    res+=orginal[j-1];
                }
            }
        }
    }
    cout<<res;
}
