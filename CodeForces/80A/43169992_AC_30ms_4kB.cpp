#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool is_prime(int i)
{
    for(int j=2;j*j<=i;j++)
    {
        if(i%j==0)
            return false;
    }
    return true;
}
int main() {
    khaled
    long long x,y;
    cin>>x>>y;
    vector<int>primes;
    for(int i=2;i<=100;i++)
    {
        if(is_prime(i))
            primes.emplace_back(i);
    }
    if(is_prime(x))
    {
        for(int i=0;i<primes.size();i++)
        {
            if(primes[i]==x)
            {
                //cout<<primes[i+1]<<line;
                if(primes[i+1]==y)
                    cout<<"YES";
                else
                    cout<<"NO";
                break;
            }
        }
    }
    else
        cout<<"NO";

}