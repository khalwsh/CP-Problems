#include<iostream>
#include<bitset>
#include<vector>
#include<algorithm>
#include<cmath>
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long l,r;
    cin>>l>>r;
    if(l==r)
        cout<<0;
    else
    {
        long long c_l=0;
        long long c=0;
        long long temp_l=l;
        long long temp_r=r;
        while(r)
        {
            c++;
            r>>=1;
            if(l>0)
            {
                c_l++;
                l>>=1;
            }
        }
        if(c_l!=c)
        {
            long long res=0;
            long long j=0;
            while(c--)
            {
                res+=pow(2,j);
                j++;
            }
            cout<<res;
        }
        else
        {
            int pos;

            bitset<64>bss(temp_l);
            bitset<64>bsss(temp_r);
            for(int i=63; i>=0; i--)
            {
                if(bss[i]!=bsss[i])
                {
                    pos=i;
                    break;
                }
            }
            long long zzz=pow(2,pos);
            bool flagg=0;
            bitset<64>zzzz(zzz);
            int kkkk=0;
            long long res=0;
            while(!flagg)
            {
            if(zzzz[kkkk]==0)
                zzzz[kkkk]=1;
            else
                break;
                kkkk++;
            }
            for(int i=0;i<64;i++)
            {
                if(zzzz[i]==1)
                    res+=pow(2,i);
            }
            cout<<res;


    }

}

}/*
#include<iostream>
#include<bitset>
#include<vector>
#include<algorithm>
#include<cmath>
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long l,r;
    cin>>l>>r;
    if(l==r)
        cout<<0;
    else
    {
        int c_l=0;
        int c=0;
        int temp_l=l;
        int temp_r=r;
        while(r)
        {
            c++;
            r>>=1;
            if(l>0)
            {
                c_l++;
                l>>=1;
            }
        }
        if(c_l!=c)
        {
            long long res=0;
            int j=0;
            while(c--)
            {
                res+=pow(2,j);
                j++;
            }
            cout<<res;
        }
        else
        {
          int max_xor=0;
          for(int i=temp_l;i<temp_r;i++)
          {
              for(int j=temp_l+1;j<=temp_r;j++)
              {
                  max_xor=max(max_xor,(i^j));
              }
          }
          cout<<max_xor;
        }

    }

}*/
