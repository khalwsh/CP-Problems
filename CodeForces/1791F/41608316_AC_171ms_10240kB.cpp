#include<bits/stdc++.h>
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
long long fast_power(long long base,long long power,long long m=2e63-1) {
    //get power in log(n) and you can set mod to adjust with the output
    if (power == 1 || power == 0)
        return base * power + (!power);
    long long res = (fast_power(base, power / 2, m) % m) % m;
    if (power & 1)
        return (((((base % m) * (res % m)) % m) * (res % m)) % m) % m;
    else
        return ((res % m) * (res % m)) % m;
}
long long gcd_ecludien_algorthim(long long a,long long b,long long &x,long long &y)
{
    //a*x+b*y=gcd(a,b)
    //this function return gcd of (a,b) and update the value of x,y to achieve the ecludien equation ax+by=gcd(a,b);
    if (b == 0) {
 
        x = 1;y = 0;return a;
    }
    long long x1, y1;
    long long d = gcd_ecludien_algorthim(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
long long mod_inverse(long long a,long long M)
{
    //(A*B)%M=1;
    //to solve this gcd(A,M) must equal to one
    //B is the x from the ecludien algorthim which it is the value returned from this function
    long long x,y;
    if(gcd_ecludien_algorthim(a,M,x,y)==1)
    {
        if(x>0)
            return x%M;
        else
            return x%M+M;
    }
    else
        return -1;
}
long long lcm(long long a,long long b)
{
    return a*(b/__gcd(a,b));
}
vector<bool> sieve_of_eratosthenes(int sz)
{
    //return the numbers which not prime in the range from 2 to size
    //o(nlog(log(n)))
    vector<bool>not_primes(sz+1,false);
    not_primes[0]=not_primes[1]=true;
    for(int i=2;i*i<=sz;i++)
    {
        if(!not_primes[i])
        {
            for(int j=i*i;j<=sz;j+=i)
            {
                not_primes[j]=true;
            }
        }
    }
    return not_primes;
}
long long my_binary_search(vector<long long>&v,long long value)
{
    int left=0;
    int right=(int)v.size()-1;
    int mid=0;
    while(left<=right) {
        mid = (right + left) / 2;
        if (v[mid] == value)
            return mid;
        else if (v[mid] > value) {
            right = mid - 1;
        } else
            left = mid + 1;
    }
 
    return mid;
}
vector<int> linear_sieve(int n)
{
    //return all prime numbers up to n;
    //o(n)
    vector<bool>not_prime(n+1);
    not_prime[0]=not_prime[1]=true;
    vector<int>primes;
    for(int i=2;i<=n;i++)
    {
        if(!not_prime[i])primes.emplace_back(i);
        for(int j=0;j<primes.size()&&i*primes[j]<=n;i++)
        {
            not_prime[i*primes[j]]=true;
            if(i%primes[j]==0)break;
        }
    }
    return primes;
}
vector<long long> segment_sieve(long long l,long long r)
{
    //take a range and get the primes within the range
    //o(r-l+l)log(r)+sqrt(r)
    r++;
    vector<bool>not_prime(r-l+1);
    for(long long i=2;i*i<=r;i++)
    {
        for(long long j=max(i*i,(l+i-1)/i*i);j<r;j+=i)
        {
            not_prime[j-l]=true;
        }
    }
    if(l==1)
        not_prime[0]=true;
    vector<long long>prime;
    for(long long i=l;i<r;i++)
    {
        if(!not_prime[i-l])
            prime.emplace_back(i);
    }
    return prime;
}
int dight_sum(int value);
int main() {
    khaled
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int q;
        cin>>q;
        vector<int>v(n);
        set<int>s;
        for(auto &val:v)
            cin>>val;
        for(int i=0;i<n;i++)
           if(v[i]>9) s.insert(i);// if it is 9 so it is one digit already
           while(q--)
           {
               int k;
               cin>>k;
               if(k==1)
               {
                   int l,r;
                   cin>>l>>r;
                   l--;r--;
                   int temp_l=l;
                   while(!s.empty())
                   {
                       set<int>::iterator it=s.lower_bound(temp_l);
                       if(it==s.end()||*it>r)
                           break;
                       else
                       {
                           v[*it]= dight_sum(v[*it]);
                           temp_l=*it+1;//not always l exist l+1 ,l+2,...,r can exist
                           if(v[*it]<=9)
                               s.erase(it);
                       }
                   }
               }
               else
               {
                   int x;
                   cin>>x;
                   x--;
                   cout<<v[x];
                   cout<<line;
               }
           }
    }
}
int dight_sum(int value)
{
    int res=0;
    while(value)
    {
        res+=value%10;
        value/=10;
    }
    return res;
}