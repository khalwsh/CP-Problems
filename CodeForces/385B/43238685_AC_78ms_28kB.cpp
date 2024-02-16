#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
pair<bool,int>found(int index,string&s)
{
    int pos=-1;
    for(int i=index;i<(int)s.size()-3;i++)
    {
        string temp;temp+=s[i];
        temp+=s[i+1];temp+=s[i+2];temp+=s[i+3];
        if(temp=="bear") {
            pos = i + 3;
            break;
        }
    }
    return make_pair(pos!=-1,(int)s.size()-pos);
}
int main() {
    khaled
    string s;
    cin>>s;
    int counter=0;
    for(int i=0;i<(int)s.size();i++)
    {
        pair<bool,int>res=found(i,s);
        if(res.first)
        {
            counter+=res.second;
        }
    }
    cout<<counter<<line;
}