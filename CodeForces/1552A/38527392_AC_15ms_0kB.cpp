#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        string before=s;
        int c=0;
        sort(s.begin(),s.end());
        for(int i=0;i<n;i++)
        {
            if(before[i]!=s[i])
                c++;
        }
        cout<<c<<endl;




    }
}
