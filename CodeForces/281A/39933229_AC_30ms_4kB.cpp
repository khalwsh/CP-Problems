/*#include<bits/stdc++.h>
#define endl '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<int>v;

bool prime(int n);
int main()
{
    khaled
    int n;
    v.push_back(2);
    v.push_back(3);
    cin>>n;
    for(int i=4; i<=n; i++)
    {
        if(prime(i))
            v.emplace_back(i);
    }
    for(auto &val:v)
        cout<<val<<" ";
    cout<<endl;
    vector<int>res;
    int z=v.size();
    for(int j=1; j<=n; j++)
    {
        int c=0;
        for(int i=0; i<z; i++)
        {
            if(j%v[i]==0)
                c++;
        }
        if(c==2)
            res.emplace_back(1);
    }
    cout<<(int)res.size();
}
bool prime(int n)
{
    for(int i=2; i<sqrt(n); i++)
    {
        if(n%i!=0)
            return false;
    }
    return true;
}*/
#include<bits/stdc++.h>
#define endl '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
bool prime(int n);
int main()
{
    khaled
    string s;
    cin>>s;
    s[0]=(char)toupper(s[0]);
    cout<<s;
}

