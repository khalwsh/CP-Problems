#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    string s;
    cin>>s;
    int left=0,right=(int)s.size()-1;
    int res=0;
    while(left<right)
    {
        if(s[left]!=s[right])
            res++;
        left++;
        right--;
    }
    cout<<res<<line;
}