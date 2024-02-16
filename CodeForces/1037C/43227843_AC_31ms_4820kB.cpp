#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    int res=0;
    for(int i=0;i<n-1;i++)
    {
        if(s1[i]!=s2[i])
        {
            if(s1[i]==s2[i+1]&&s2[i]==s1[i+1])
                swap(s1[i],s1[i+1]),res++;
            else
                s1[i]=s2[i],res++;
        }
    }
    if(s1[n-1]!=s2[n-1])
        res++;
    cout<<res<<line;
}