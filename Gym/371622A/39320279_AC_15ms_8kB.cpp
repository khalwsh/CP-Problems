#include<iostream>
#include<vector>
#include<set>
#include<map>
#define endl '\n'
#include<cmath>
#include<bitset>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    bitset<32>s(n);
    int counter=0;
    for(int i=0;i<32;i++)
    {
     if(s[i]==1)
            counter++;
    }
    cout<<counter;
}
