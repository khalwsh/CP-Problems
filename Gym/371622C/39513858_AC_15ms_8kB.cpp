#include<iostream>
#include<bitset>
#define endl '\n'
using namespace std;
int main()
{

    long long a,b;
    cin>>a>>b;
    long long temp_a=a,temp_b=b;
    long long counter_b=0,counter_a=0;
    while(b)
    {
        counter_b++;
        if(a>0)
            counter_a++;
        a>>=1,b>>=1;
    }
    if(counter_a==counter_b)
    {
        bitset<64>b_b(temp_b);
        bitset<64>b_a(temp_a);
        long long other_ones=0;
        for(long long i=counter_b-2; i>=0; i--)
        {
            if(b_b[i]==1)
            {
                other_ones++;
            }
            else
                break;
        }
        long long ones=0;
        for(long long i=counter_a-2; i>=0; i--)
        {
            if(b_a[i]==1)
            {
                ones++;
            }
            else
                break;
        }
        int res=0;
        res+=other_ones-ones;
        other_ones=0;
        for(long long i=0; i<counter_b; i++)
        {
            if(b_b[i]==1)
                other_ones++;

        }
        if(other_ones-counter_b==-1)
            res++;
        other_ones=0;
        /*for(long long i=0; i<counter_a; i++)
        {
            if(b_a[i]==1)
                other_ones++;

        }
        if(other_ones-counter_a==-1)
            res++;*/
        cout<<res;
    }
    else
    {
        bitset<64>b_b(temp_b);
        bitset<64>b_a(temp_a);
        long long tem=counter_a;
        for(long long i=counter_a-1; i>=0; i--)
        {
            if(b_a[i]==1)
                counter_a--;
            else
                break;
        }
        long long res=0;
        res+=counter_a;
        long long c=counter_b-tem-1;
        long long k=0;
        while(c--)
        {
            res+=tem+k;
            k++;
        }
        long long other_ones=0;
        for(long long i=counter_b-2; i>=0; i--)
        {
            if(b_b[i]==1)
            {
                other_ones++;
            }
            else
                break;
        }
        res+=other_ones;
        other_ones=0;
        for(long long i=0; i<counter_b; i++)
        {
            if(b_b[i]==1)
                other_ones++;

        }
        if(other_ones-counter_b==-1)
            res++;
        cout<<res;
    }


}
