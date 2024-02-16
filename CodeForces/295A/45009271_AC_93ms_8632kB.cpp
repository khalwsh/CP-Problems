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
long long fast_power( long long base, long long power,long long mod)
{
    if(power==0)
        return 1;
    long long res = fast_power(base, power / 2,mod) % mod;
    res = ((res % mod) * (res % mod)) % mod;
    if (power & 1)
        return (res % mod) * (base % mod) % mod;
    else
        return res % mod;
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
vector<long long> linear_sieve(long long n)
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
template<class T>
class  vector_stack
{
private:
    int top;
    int length;
    int capcity;
    int middle;
    T*arr;
    void extend_capcity()
    {
        T *temp=new T[2*(1+capcity)]{ };
        capcity*=2;
        capcity+=2;
        for(int i=0;i<length;i++)
        {
           temp[i]=arr[i];
        }
        delete[] arr;
        arr=new T[capcity]{};
        for(int i=0;i<length;i++)
        {
            arr[i]=temp[i];
        }
        delete[] temp;
        top=length-1;
    }
public:
    vector_stack():top(-1),length(0),capcity(0),arr(nullptr),middle(0)
    {

    }
    vector_stack(int siz):top(siz-1),length(siz),capcity(siz),arr(new T[siz]),middle(siz/2)
    {
        //top=-1,length=siz,capcity=siz;
        //arr=new int[siz];
    }
    void push_elements(T value)
    {
        if(length==capcity)
            extend_capcity();
        top++;
        middle=top/2;
        arr[top]=value;
        length++;
    }
    T peek()
    {
         // if(top>=0)
        return arr[top];
    }
    ~vector_stack()
    {
        delete[]arr;
    }
    void pop()
    {
        if(!length)
            return;
        top--;
        middle=top/2;
        length--;
    }
    bool empty()
    {
       return length==0;
    }
    bool size()
    {
        return length;
    }
    void shift_right()
    {
        top++;
        if(length==capcity) {
            T *temp = new T[capcity + 1];
            for (int i = 0; i < capcity + 1; i++) {
                temp[i] = arr[i];
            }
            capcity++;
            for (int i = length; i >= 0; i--) {
                swap(temp[i], temp[i + 1]);
            }
            delete[]arr;
            arr = new T[capcity];
            for (int i = 1; i < capcity; i++) {
                arr[i] = temp[i];
            }
        }
        else
        {
            for (int i = length; i >= 0; i--) {
                swap(arr[i], arr[i + 1]);
            }
        }
        top=middle/2;
    }
    void insert_at_bottom(T value)
    {
        /*shift_right();
        arr[0]=value;
        length++;*/
        if(empty()) {
            push_elements(value);
            return;
        }
        T temp=peek();
        pop();
        insert_at_bottom(value);
        push_elements(temp);
    }
    void reverse()
    {
       /* int left=0,right=length-1;
        while(left<=right)
        {
            swap(arr[left],arr[right]);
            left++;
            right--;
        }*/
       if(empty())
           return;
        T cur=peek();
        pop();
        reverse();
        insert_at_bottom(cur);
    }
    void delete_middle()
    {
        for(int i=middle+1;i<length;i++)
        {
            swap(arr[i],arr[i-1]);
        }
        top--;
        length--;
        middle=top/2;
    }
};
template<typename TT>
struct Node
{
    TT data{};
    Node*next{nullptr};
};
template<class TT>
class  linked_list_stack
{
private:
    Node<TT>*head;
    int length{0};
public:
    linked_list_stack()
    {
        head= nullptr;
        length=0;
    }
    bool empty()
    {
        return this->length==0;
    }
    int size()
    {
        return this->length;
    }
    void insert(TT value)
    {
        if(length==0)
        {
            head=new Node<TT>{};
            head->data=value;
            head->next=nullptr;
        }
        else
        {
            Node<TT>*temp;
            temp=new Node<TT>{};
            temp->data=value;
            temp->next=head;
            head=temp;
        }
        length++;
    }
    TT top()
    {
        return head->data;
    }
    void pop()
    {
        if(length==0)
            return;
        if(length==1)
        {
            delete head;
            head= nullptr;
        }
        else {
            Node<TT> *temp_head = head->next;
            delete head;
            head = temp_head;
        }
        length--;
    }

};
double evaluate_postfix(string &s)
{
    linked_list_stack<double>numbers;
    for(auto &val:s)
    {
        if(isdigit(val))
            numbers.insert(val-'0');
        else
        {
            double a=numbers.top();numbers.pop();
            double b=numbers.top();numbers.pop();
            if(val=='+')
                numbers.insert(a+b);
            else if(val=='*')
                numbers.insert(a*b);
            else if(val=='-')
                numbers.insert(b-a);
            else if(val=='/')
                numbers.insert(b/a);
            else if(val=='^')
                numbers.insert((double)pow(b,a));
        }
    }
    return numbers.top();
}
vector<char> convert_infix_to_postfix(string &s)
{
    map<char,int>mp;
    mp['+']=0;
    mp['-']=0;
    mp['*']=1;
    mp['/']=1;
    mp['^']=2;
    vector<char>res;
    vector_stack<char>temp;
    for(auto &val:s)
    {
        if(val=='(')
            temp.push_elements(val);
        else if(val==')')
        {
            while(temp.peek()!='(')
            {
                res.emplace_back(temp.peek());
                temp.pop();
            }
            temp.pop();
        }
        else if(!temp.empty()&&temp.peek()=='('&&val!='('&&val!=')')
        {
            if(isdigit(val))
                res.emplace_back(val);
            else
                temp.push_elements(val);
        }
        if(isdigit(val))
            res.emplace_back(val);//o(1)
        else if(!isdigit(val)&&temp.empty())//o(1)
            temp.push_elements(val);//o(1)
        else if(mp[val]<=mp[temp.peek()])//o(1)
        {
            while(mp[val]<=mp[temp.peek()])//o(1)
            {
                if(mp[val]==2&&mp[temp.peek()]==2)
                    break;
                if(temp.empty())//o(1)
                    break;
                res.emplace_back(temp.peek());
                temp.pop();
            }
            temp.push_elements(val);
        }
        else if(mp[val]>mp[temp.peek()])
        {
            temp.push_elements(val);
        }
    }
    while(!temp.empty())
    {
        res.emplace_back(temp.peek());
        temp.pop();
    }
    return res;
}
int main() {
    khaled
    long long n,m,k;
    cin>>n>>m>>k;
    long long temp_m=m,temp_k=k;
    vector<long long>v(n);
    vector<long long>operations(m+5);
    for(auto &vla:v)
        cin>>vla;
    vector<pair<long long,pair<long long,long long>>>vp;
    vector<pair<long long,long long>>ends;
    while(temp_m--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        vp.emplace_back(make_pair(x,make_pair(y,z)));
        ends.emplace_back(make_pair(x,y));
    }
    while(temp_k--)
    {
        int l,r;
        cin>>l>>r;
        l--;
        operations[l]+=1;
        operations[r]+=-1;
    }
    for(int i=1;i<m;i++)
    {
        operations[i]+=operations[i-1];
    }
    vector<long long>new_one(n+5);
    for(int i=0;i<m;i++)
    {
        new_one[ends[i].first]+=vp[i].second.second*operations[i];
        new_one[ends[i].second]+=-(vp[i].second.second*operations[i]);
        //cout<<ends[i].first<<" "<<ends[i].second<<line;
    }
    for(int i=1;i<n;i++)
        new_one[i]+=new_one[i-1];
    for(int i=0;i<n;i++)
        cout<<new_one[i]+v[i]<<" ";














}