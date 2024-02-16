#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
int main() {
    khaled
    string s;
    while(getline(cin,s)&&s!="")
    {
        int word_count=0;
        bool flag=false;
        for(auto &val:s)
        {

            if(val>=65&&val<=90||val>=97&&val<=122)
            {
                if(!flag)
                    flag=true,word_count++;
            }
            else {
                flag=false;
            }
        }
        cout<<word_count<<line;
    }
}