#include<iostream>
#include<set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    set<char>se;
    set<char>::iterator it=se.begin();
    for(int i=0;i<n;i++)
    {
        s[i]=(char)tolower(s[i]);
       it=se.emplace_hint(it,s[i]);
    }

    if(se.size()==26)
        cout<<"YES";
    else
        cout<<"NO";

}
