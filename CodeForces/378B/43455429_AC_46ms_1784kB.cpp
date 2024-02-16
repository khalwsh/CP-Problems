#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int n;
    cin>>n;
    vector<long long>first_semi_final(n),second_semi_final(n);
    for(int i=0;i<n;i++)
    {
        long long value1,value2;
        cin>>value1>>value2;
        first_semi_final[i]=value1,second_semi_final[i]=value2;
    }
    string s1,s2;
    s1.resize(n),s2.resize(n);
    for(int i=n/2-1;i>=0;i--)
    {
        s1[i]=s2[i]='1';
    }
    for(int i=n/2;i<n;i++)s1[i]=s2[i]='0';
    int team1=0,team2=0;
    for(int i=0;i<n;i++)
    {
        if(first_semi_final[team1]<=second_semi_final[team2])
        {
            s1[team1++]='1';
        }
        else
            s2[team2++]='1';
    }
    cout<<s1<<line<<s2<<line;
}