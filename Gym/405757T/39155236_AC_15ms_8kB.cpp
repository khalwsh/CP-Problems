#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    char ch1,ch2;
    int my_max=-1;
    int c=0;
    for(int i=0; i<n-1; i++)
    {
        c=0;
        for(int j=0; j<n-1; j++)
        {
            if(s[j]==s[i]&&s[j+1]==s[i+1])
            {
                c++;
            }
        }
        if(my_max<c)
        {
            my_max=c;
            ch1=s[i];
            ch2=s[i+1];
        }
    }
    cout<<ch1<<ch2;
}
