#include<bits/stdc++.h>
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main() {
    khaled
    long long N;
    cin>>N;
    bitset<64>b(N);
    int pos=0;
    for(int i=0;i<64;i++)
    {
        if(b[i]==1)
            pos=i;
    }
    cout<<(pos);
}