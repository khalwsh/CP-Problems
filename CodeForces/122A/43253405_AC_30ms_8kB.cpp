#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
set<int>all;
void generate_lucky(int n)
{
    if(n>=1000)
        return;
    all.insert(n);
    generate_lucky(n*10+4);
    generate_lucky(n*10+7);
}
int main() {
    khaled
    int n;
    cin>>n;
    bool done=false;
    generate_lucky(4);
    generate_lucky(7);
    for(auto &val:all)
    {
        if(n%val==0)
        {
            done=true;
            break;
        }
    }
    if(done)
        cout<<"YES";
    else
        cout<<"NO";
}