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
        b>>=1ll;
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
    Node*next{},*prev{};
};
template<typename T>
class doubly_linked_list{
private:
    Node<T>*head{};
    Node<T>*tail{};
    int length{};
    void format()
    {
        while(length!=0)
            delete_first();
    }
public:
    doubly_linked_list(const doubly_linked_list<T>& copy)=delete;
    doubly_linked_list<T>&operator=(const doubly_linked_list<T>&assign)=delete;
    void clear()
    {
        format();
    }
    doubly_linked_list()
    {
        this->head=this->tail=nullptr;
        length=0;
    }
    ~doubly_linked_list()
    {
       clear();
    }
    void push_front(T value)
    {
        if(!length)
        {
            head=new Node<T>{};
            tail=new Node<T>{};
            head->data=value;
            head->prev=nullptr;
            head->next=nullptr;
            tail->data=value;
            tail->prev=head;
            tail->next=nullptr;
        }
        else if(length==1)
        {
            head->data=value;
            head->prev=nullptr;
            head->next=tail;
        }
        else
        {
            auto temp=new Node<T>{};
            temp->data=value;
            temp->prev=nullptr;
            head->prev=temp;
            temp->next=head;
            head=temp;
            temp= nullptr;
        }
        length++;
    }
    void push_back(T value)
    {
        if(!length)
        {
            push_front(value);
            return;
        }
        else if(length==1)
        {
            tail->data=value;
            tail->next=nullptr;
            tail->prev=head;
            head->prev=nullptr;
            head->next=tail;
        }
        else
        {
            auto temp=new Node<T>{};
            temp->data=value;
            temp->next=nullptr;
            temp->prev=tail;
            tail->next=temp;
            tail=temp;
            temp= nullptr;
        }
        length++;
    }
    void insert(int pos,T value)
    {
        if(pos<=0||pos>length)
            return;
        if(pos==1)
        {
            push_front(value);
            return;
        }
        else if(pos==length)
        {
            push_back(value);
            return;
        }
        auto temp=head;
        while(--pos)
            temp=temp->next;
       auto new_node=new Node<T>{};
        new_node->data=value;
        new_node->next=temp;
        new_node->prev=temp->prev;
        temp->prev->next=new_node;
        temp->prev=new_node;
    }
    void display_forward()
    {
        auto temp=head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<line;
    }
    void display_backward()
    {
        auto temp=tail;
        while(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
        cout<<line;
    }
    void delete_first()
    {
        if(!length)
            return;
        else if(length==1)
        {
            delete head;
            //delete tail;
            head=tail=nullptr;
            length--;
            return;
        }
        auto temp=head;
        head=head->next;
        head->prev=nullptr;
        delete temp;
        temp=nullptr;
        length--;

    }
    void delete_last()
    {
        if(length==0||length==1)
            delete_first();
        else
        {
            auto temp=tail;
            tail=tail->prev;
            tail->next=nullptr;
            delete temp;
            temp=nullptr;
            length--;
        }
    }
    void remove_key(T value)
    {
        if(!length||length==1&&head->data!=value)
            return;
        if(head->data==value) {
            delete_first();
            return;
        }
        auto temp=head;
        while(temp!=nullptr&&temp->data!=value)
        {
            temp=temp->next;
        }
        if(temp==nullptr)
            return;
        if(temp->next==nullptr) {
            delete_last();
            return;
        }
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        delete temp;
        temp=nullptr;
    }
};
template<class T>
struct tree_Node{
    T data{};
    tree_Node*left{};tree_Node*right{};
};
template<typename T>
void print_tree_postfix(tree_Node<T>*root)
{
    if(root==nullptr)
    {
        return;
    }
    print_tree_postfix(root->left);
    print_tree_postfix(root->right);
    cout<<root->data<<" ";
}
template<class T>
void print_tree_prefix(tree_Node<T>*root)
{
    if(!root)
        return ;
    cout<<root->data<<" ";
    print_tree_prefix(root->left);
    print_tree_prefix(root->right);
}
template<class T>
void print_tree_inorder(tree_Node<T>*root)
{
   if(!root)
       return;
    print_tree_inorder(root->left);
    cout<<root->data<<" ";
    print_tree_inorder(root->right);
}
template<class T>
void clear(tree_Node<T>*&root)
{
    if(!root)
        return;
    clear(root->left);
    clear(root->right);
    delete root;
    root= nullptr;
}
template<class T>
class binary_search_tree
{
private:
    tree_Node<T>*root{};
    int length{};
    void print_inorder(tree_Node<T>*temp)
    {
        if(temp== nullptr)
            return;
        print_inorder(temp->left);
        cout<<temp->data<<" ";
        print_inorder(temp->right);
    }
    pair<tree_Node<T>*,tree_Node<T>*> min_right(tree_Node<T>*temp)
    {
        tree_Node<T>*parent=temp;
        temp=temp->right;
        while(temp->left!=nullptr) {
            parent = temp;
            temp = temp->left;
        }
        return make_pair(parent,temp);
    }
    tree_Node<T>* max_left(tree_Node<T>*temp)
    {
        temp=temp->left;
        while(temp->right!=nullptr)
            temp=temp->right;
        return temp;
    }
public:
    binary_search_tree()
    {
        this->root=nullptr;
        this->length=0;
    }
    void insert(T value)
    {
        if(length==0)
        {
            root=new tree_Node<T>{};
            root->data=value;
            root->right=nullptr;
            root->left=nullptr;
        }
        else
        {
            tree_Node<T>*temp=root;
            tree_Node<T>*prev= nullptr;
            auto new_node=new tree_Node<T>{};
            new_node->data=value;
            new_node->right=new_node->left=nullptr;
            while(temp!=nullptr)
            {
                prev=temp;
                //if(temp->data==value)
                //  return;
                if(value>temp->data)
                    temp=temp->right;
                else
                    temp=temp->left;
            }
            if(value>prev->data)
            {
               prev->right=new_node;
            }
            else
                prev->left=new_node;
            //new_node=nullptr;
        }
        length++;
    }
    void print_inorder()
    {
        print_inorder(root);
        cout<<line;
    }
    int size()
    {
        return length;
    }
    bool empty()
    {
        return length==0;
    }
    tree_Node<T>* find(T value)
    {
        if(length==0)
            return nullptr;
        tree_Node<T>*temp=root;
        while(temp!=nullptr)
        {
            if(temp->data==value)
               return temp;
            if(value>temp->data)
                temp=temp->right;
            else
                temp=temp->left;
        }
        return nullptr;
    }
};
template<typename T>
class binary_tree{
private:
    T data{};
    binary_tree *left{};
    binary_tree *right{};
public:
    binary_tree()
    {
        left=nullptr;
        right=nullptr;
        data={};
    }
    binary_tree(T value)
    {
        data=value;
        left=right=nullptr;
    }
    void add(vector<T>values,string path)
    {
        int n=(int)values.size();
        binary_tree<T>*current=this;
        for(int i=0;i<n;i++)
        {
            if(path[i]=='L')
            {
               if(!current->left)
               {
                   current->left=new binary_tree<T>{};
                   current->left->data=values[i];
               }
               current=current->left;
            }
            else
            {
                if(!current->right)
                {
                    current->right=new binary_tree<T>{};
                    current->right->data=values[i];
                }
                current=current->right;
            }
        }
    }
    void print_inorder()
    {
        if(left)
            left->print_inorder();
        cout<<data<<" ";
        if(right)
            right->print_inorder();
    }
    T max_value()
    {
        T res=this->data;
        if(left)
            res=max(res,left->max_value());
        if(right)
            res=max(res,right->max_value());
        return res;
    }
    int tree_height()
    {
        if(left&&right)
            return 1+max(left->tree_height(),right->tree_height());
        else if(!left&&right)
            return 1+right->tree_height();
        else if(!right&&left)
            return 1+left->tree_height();
        else
            return 0;
    }
    int total_number_of_nodes()
    {
        int res=1;
        if(left)
            res+=left->total_number_of_nodes();
        if(right)
            res+=right->total_number_of_nodes();
        return res;
    }
    int count_leaf_nodes()
    {
        static int counter=0;
        if(!left&&!right)
            counter++;
        if(left)
            left->count_leaf_nodes();
        if(right)
            right->count_leaf_nodes();
        return counter;
    }
    bool search(T value)
    {
        if(data==value)
            return true;
        if(left)
            return left->search(value);
        if(right)
            return right->search(value);
        else
            return false;
    }
    bool is_perfect()
    {
        return total_number_of_nodes()==((1<<(tree_height()+1))-1);
    }
};
int main() {
    khaled
    int n;
    cin>>n;
    vector<long long>v(n);
    map<long long,int>mp;
    for(auto &val:v)
        cin>>val,mp[val]++;
    int res=0;
    for(int i=0;i<n;i++)
    {
        long long k=1;
        while(k<v[i])
            k<<=1;
        long long last=0;
        while(k<=1000000000000000000)
        {
            if(last>k)
                break;
            if(mp[k-v[i]]!=0)
            {
                if(mp[k-v[i]]==1&&k-v[i]!=v[i]||mp[k-v[i]]>1)
                {
                    res++;break;
                }
            }
            last=k;
            k<<=1;
        }

    }
    cout<<n-res<<line;
}