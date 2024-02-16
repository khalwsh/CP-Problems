#include<bits/stdc++.h>
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
long long mulmod(long long a,long long b,long long mod=INT64_MAX)
{
    long long res=0,y=a%mod;
    while(b>0)
    {
        if(b&1)
        {
            res=((res%mod)+(y%mod))%mod;
        }
        y=((y%mod)*(2ll%mod))%mod;
        b>>=1;
    }
    return (res%mod);
}
long long fast_power(long long base,long long power,long long m=INT64_MAX) {
    //get power in log(n) and you can set mod to adjust with the output
    if (power == 1 || power == 0)
        return base * power + (!power);
    long long res = (fast_power(base, power / 2, m) % m) % m;
    if (power & 1)
        return mulmod(base,mulmod(res,res,m),m);
        //return ((((((base % m) * (res % m)) % m) * (res % m)) % m) % m+m)%m;
    else
        return mulmod(res,res,m);
    //return( ((res % m) * (res % m)) % m+m)%m;
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
long long euler_totient_function(long long n)
{
    if(n==1)
        return 1;
    set<long long>prime_factors;
    //calculate how many number smaller than or equal n and coprime with n gcd(n,x:0<x<n)==1
    auto res=(double)n;
    for(long long i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            prime_factors.insert(i);
            n/=i;
        }
    }
    if(n!=1) {
        prime_factors.insert(n);
    }
    for(auto &val:prime_factors)
    {
        res*=(1.0-1.0/(double )val);
    }
    prime_factors.clear();
    return(long long)res;

}
long long mod_inverse(long long B,long long M)
{
    //(A*B)%M=1;
    //to solve this gcd(A,M) must equal to one
    //B is the x from the ecludien algorthim which it is the value returned from this function
    //we also can get the multiblicative inverse by take a which we want to get it's inverse
    //and raise it to the power of the value of the eulwer totient function of(mod)
    //a^(phi(mod)-1)%mod;
    return fast_power(B, euler_totient_function(M)-1,M);
}
long long lcm(long long a,long long b)
{
    return a*(b/__gcd(a,b));
}
vector<long long> sieve_of_eratosthenes(long long n)
{
    //return the numbers which  prime in the range from 1 to size
    //o(nlog(log(n)))
    vector<bool>primes(n+1,true);
    primes[0]=primes[1]=false;
    for(long long i=2;i*i<=n;i++)
    {
        if(primes[i])
        {
            for(long long j=i*i;j<=n;j+=i)
            {
                primes[j]=false;
            }
        }
    }
    vector<long long>prime_numbers;
    for(long long i=0;i<n+1;i++)
    {
        if(primes[i])
            prime_numbers.emplace_back(i);

    }
    return prime_numbers;

}
vector<long long> linear_sieve(int n)
{
    //return all primes in range form [1,n] in o(n)
    vector<bool>prime(n+1,true);
    prime[0]=prime[1]=false;
    vector<long long>returned_primes;
    for(long long i=2;i<=n;i++)
    {
        if(prime[i])
            returned_primes.emplace_back(i);

        for(auto &val:returned_primes)
        {
            if(val*i>n)
                break;
            prime[val*i]=false;
        }

    }
    prime.clear();
    return returned_primes;
}
vector<long long> segment_sieve(long long l,long long r)
{
    //take a range and get the primes within the range
    //o(r-l+l)log(r)+sqrt(r)
    //to make integer ceil(l/i)----->(l+i-1)/i;
    //to get first number k|x  by k and bigger than n ---->  ((n+k-1)/k)*k;
    vector<bool>prime(r-l+1,true);
    for(long long i=2;i*i<=r;i++)
    {
        for(long long j=max(i*i,((l+i-1)/i)*i);j<=r;j+=i)
        {
            prime[j-l]=false;
        }
    }
    if(l==1)
        prime[0]=false;
    vector<long long>returned_primes;
    for(long long i=l;i<=r;i++)
    {
        if(prime[i-l])
            returned_primes.emplace_back(i);
    }
    return returned_primes;
}
long long solve_system_of_equation_using_chinese_reminder_theory(vector<long long>rem,vector<long long>mods)
{
    //solve for mods are coprime;
    long long prod=1,res=0;
    for(auto &val:mods)
        prod*=val;
    for(int i=0;i<(int)mods.size();i++)
    {
        long long sub_prod=prod/mods[i];
        res+=sub_prod* mod_inverse(sub_prod,mods[i])*rem[i];
    }
    return res%prod;
}
bool fermat_prime_testing(long long n,int number_of_moves=2000)
{
    // if n is prime and b is a natural number such that 1<b<n;
    // the following equation come true
    // (b^(n-1))%n=1
    // using mulmod in the fast power to make sure to avoid overflow
    //if p is a prime number so (p-1)!%p=p-1
    if(n==1||n==4||n==0)
        return false;
    if(n==2||n==3||n==5)
        return true;
    while(number_of_moves--)
    {
        if(fast_power((long long)2+rand()%(n-3),n-1,n)!=1)
            return false;
    }
    return true;
}
bool robin_muller_prime_test(long long n,int number_of_moves=2000)
{
    // factorize the n-1 to powers of 2 and an odd number
    // check if a: 1<a<n a^(d)==1||n-1 if true probably prime;
    // check if a: 1<a<n a^(2^(r)*d)==n-1||-1 if true probably prime
    // iterate for a number of moves if all true
    // there is big probality it is a prime
    return -1;
}
int main() {
    khaled
    long long n;
    long long x1,y1,x2,y2;
    cin>>n>>x1>>y1>>x2>>y2;
    string s;
    cin>>s;
    long long east=-1,west=-1,north=-1,south=-1;
    long long res=0;
    if(x1==x2&&y1==y2)
        cout<<0<<line;
    else {
        if(x1<x2)
        {
            east=x2-x1;
        }
        else if(x2<=x1)
        {
            west=x1-x2;
        }
        if(y1>y2)
        {
            south=y1-y2;
        }
        else
        {
            north=y2-y1;
        }
        long long counter_orginal=0;
        if(east!=-1)
        {
            long long counter_res=0,counter=0;
            for(auto &val:s)
            {
                if(counter==east) {
                    counter_orginal++;
                    break;
                }
                if(val=='E')
                    counter++;
                counter_res++;
                if(counter==east) {
                    counter_orginal++;
                    break;
                }
            }
            res=max(res,counter_res);
        }
        if(west!=-1)
        {
            long long counter_res=0,counter=0;
            for(auto &val:s)
            {
                if(counter==west) {
                    counter_orginal++;
                    break;
                }
                if(val=='W')
                    counter++;
                counter_res++;
                if(counter==west)
                {
                    counter_orginal++;
                    break;
                }
            }
            res=max(res,counter_res);

        }
        if(north!=-1)
        {
            long long counter_res=0,counter=0;
            for(auto &val:s)
            {
                if(counter==north)
                {
                    counter_orginal++;
                    break;
                }
                if(val=='N')
                    counter++;
                counter_res++;
                if(counter==north)
                {
                    counter_orginal++;
                    break;
                }
            }
            res=max(res,counter_res);
        }
        if(south!=-1)
        {
            long long counter_res=0,counter=0;
            for(auto &val:s)
            {
                if(counter==south)
                {
                    counter_orginal++;
                    break;
                }
                if(val=='S')
                    counter++;
                counter_res++;
                if(counter==south)
                {
                    counter_orginal++;
                    break;
                }
            }
            res=max(res,counter_res);
        }
        if(res==n)
        {
            if(counter_orginal==2)
                cout<<res<<line;
            else
                cout<<-1<<line;
        }
        else
          cout<<res<<line;
    }
}