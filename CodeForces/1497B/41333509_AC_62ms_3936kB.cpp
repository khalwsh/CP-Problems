#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
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
long long fast_power( long long base, long long power,long long mod=INT64_MAX)
{
    if(power==0)
        return 1;
    long long res = fast_power(base, power / 2,mod) % mod;
    res = ((res % mod) * (res % mod)) % mod;
    if (power & 1)
        return ((res % mod) * (base % mod)) % mod;
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
long long solve_system_of_equation_using_chinese_reminder_theory(vector<long long>&rem,vector<long long>&mods)
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
        if(fast_power((long long)2+std::rand()%(n-3),n-1,n)!=1)
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
string convert_infix_to_postfix(string &s)
{
    map<char,int>mp;
    stack<char>sk;
    mp['+']=1;
    mp['-']=1;
    mp['*']=2;
    mp['/']=2;
    mp['^']=3;
    string res;
    for(auto &val:s)
    {
        if(isdigit(val)|| isupper(val)|| islower(val))
        {
           res+=val;
        }
        else if(sk.empty()||val=='('||!sk.empty()&&sk.top()=='(')
        {
            sk.push(val);
        }
        else if(val==')')
        {
            while(sk.top()!='(')
            {
                res+=sk.top();
                sk.pop();
            }
            sk.pop();
        }
        else
        {
            while(!sk.empty()&&mp[val]<=mp[sk.top()])
            {
                if(val=='^'&&sk.top()=='^')
                    break;
                res+=sk.top();
                sk.pop();
            }
            sk.push(val);
        }
    }
    while(!sk.empty())
        res+=sk.top(),sk.pop();
    return res;
}
string convert_infix_to_postfix_reversed(string &s)
{
    map<char,int>mp;
    stack<char>sk;
    mp['+']=1;
    mp['-']=1;
    mp['*']=2;
    mp['/']=2;
    mp['^']=3;
    string res;
    for(auto &val:s)
    {
        if(isdigit(val)|| isupper(val)|| islower(val))
        {
            res+=val;
        }
        else if(sk.empty()||val=='('||!sk.empty()&&sk.top()=='(')
        {
            sk.push(val);
        }
        else if(val==')')
        {
            while(sk.top()!='(')
            {
                res+=sk.top();
                sk.pop();
            }
            sk.pop();
        }
        else
        {
            while(!sk.empty()&&mp[val]<mp[sk.top()]||!sk.empty()&&mp[val]==mp[sk.top()]&&val=='^')
            {
                res+=sk.top();
                sk.pop();
            }
            sk.push(val);
        }
    }
    while(!sk.empty())
        res+=sk.top(),sk.pop();
    return res;
}
double convert_from_string_to_int(char &s)
{
    stringstream ss;
    ss<<s;
    double temp;
    ss>>temp;
    return temp;
}
double operation(double c,double d,char sign)
{
    if(sign=='^')
        return pow(c,d);
    else if(sign=='+')
        return c+d;
    else if(sign=='*')
        return c*d;
    else if(sign=='-')
        return c-d;
    else
        return c/d;
}
long double evaluate_postfix(string &s)
{
    stack<double>numbers;
    for(auto &val:s)
    {
        if(isdigit(val))
            numbers.push((convert_from_string_to_int(val)));
        else
        {
            double a=numbers.top();
            numbers.pop();
            double b=numbers.top();
            numbers.pop();
            numbers.push(operation(b,a,val));
        }
    }
    return numbers.top();
}
string infix_to_prefix(string &s)
{
    string reverse_infix;
    for(int i=(int)s.size()-1;i>=0;i--)
    {
        if(s[i]=='(')
            reverse_infix+=')';
        else if(s[i]==')')
            reverse_infix+='(';
        else
            reverse_infix+=s[i];
    }
    string reversed_postfix= convert_infix_to_postfix_reversed(reverse_infix);
    string prefix;
    for(int i=(int)reversed_postfix.size()-1;i>=0;i--)
    {
        prefix+=reversed_postfix[i];
    }
    return prefix;
}
template<class T>
struct Node{
    T data{};
    Node*next{};
};
template<typename TT>
class linked_list{
private:
    Node<TT>*head{};
    int length=0;
    Node<TT>*tail{};
    void reverse_recusion(Node<TT>*temp)
    {
        if(temp== nullptr)
            return;
        reverse_recusion(temp->next);
        TT value=temp->data;
        push_back(value);

    }
public:
    void remove_first()
    {
        if(!length)
            return;
        else if(length==1)
        {
            delete head;
            head=tail= nullptr;
            length--;
        }
        else
        {
            Node<TT>*temp=head;
            head=head->next;
            delete temp;
            temp= nullptr;
            length--;
        }
    }
    void remove_last()
    {
        if(length==0||length==1)
        {
            remove_first();
            return;
        }
        else
        {
            Node<TT>*cur=head->next;
            Node<TT>*prev=head;
            while(cur!=tail)
            {
                prev=cur;
                cur=cur->next;
            }
            tail=prev;
            delete cur;
            cur= nullptr;
            tail->next=nullptr;
            length--;
        }
    }
    linked_list()
    {
        this->length=0;
        head= nullptr;
        tail= nullptr;
    }
    void push_back(TT value)
    {
        if(length==0)
        {
            head=new Node<TT>{};
            head->data=value;
            head->next=nullptr;
            tail= nullptr;
        }
        else if(length==1)
        {
            tail=new Node<TT>{};
            tail->data=value;
            tail->next=nullptr;
            head->next=tail;
        }
        else
        {
            auto newnode=new Node<TT>{};
            newnode->data=value;
            newnode-> next=nullptr;
            tail->next=newnode;
            tail=newnode;
        }
        length++;
    }
    void push_front(TT value)
    {
        if(!length)
        {
            push_back(value);
            return;
        }
        else if(length==1)
            {
                tail=new Node<TT>{};
                tail->data=head->data;
                tail->next=nullptr;
                head->data=value;
                head->next=tail;
                length++;
            }
        else
        {
            auto new_node=new Node<TT>{};
            new_node->data=value;
            new_node->next=head;
            head=new_node;
            length++;
        }

    }
    void delete_key(TT value)
    {
        if(length==0||head->data==value)
        {
            remove_first();
            return;
        }
        else
        {
            Node<TT>*cur=head->next;
            Node<TT>*prev=head;
            while(cur!= nullptr&&cur->data!=value)
            {
                prev=cur;
                cur=cur->next;
            }
            if(cur==tail) {
                remove_last();
                return;
            }
            if(cur== nullptr)
                return;
            prev->next=cur->next;
            delete cur;
            cur= nullptr;
            length--;
        }
    }
    void print()
    {
        if(!length)
            return;
        Node<TT>*cur=head;
        while(cur!= nullptr)
        {
            cout<<cur->data<<" ";
            cur=cur->next;
        }
    }
    void reverse_rec()
    {
        reverse_recusion(head);
        int n=length/2;
        int temp=n;
        while(n--)
        {
            remove_first();
        }
        length=temp;
    }
    void reverse_iterative()
    {
        if(length==0||length==1)
            return;
        Node<TT>*prev=nullptr;
        Node<TT>*cur=head;
        Node<TT>*next=cur->next;
        while(next!= nullptr)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        tail=head;
        head=prev;
    }
};
struct tree_Node{
    int data{};
    tree_Node*left{};tree_Node*right{};
};
void print_tree(tree_Node*&root)
{
    if(root==nullptr)
    {
        return;
    }
    cout<<root->data<<line;
    print_tree(root->left);
    print_tree(root->right);
}
int main() {
    khaled
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        map<int, int> cnt;
        while (n--) {
            int x;
            cin >> x;
            cnt[x % m]++;
        }
        int ans = 0;
        for (auto &c : cnt) {
            if (c.first == 0) ans++;
            else if (2 * c.first == m) {
                ans++;
            } else if (2 * c.first < m || cnt.find(m - c.first) == cnt.end()) {
                int x = c.second, y = cnt[m - c.first];
                ans += 1 + max(0, abs(x - y) - 1);
            }
        }
        cout << ans << '\n';
    }

}




