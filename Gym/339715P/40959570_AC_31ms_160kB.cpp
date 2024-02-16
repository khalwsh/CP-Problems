#include<bits/stdc++.h>
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
long long fast_power(long long base,long long power,long long m=INT64_MAX) {
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
struct Node
{
    int data{};
    Node* next{};
    Node* prev{};
    explicit Node(int data=0)
    {
        this->data= data;
        this->next= nullptr;
        this->prev= nullptr;
    }
    void set(Node* Next,Node* Prev)
    {
        this->next=Next;
        this->prev=Prev;
    }
};
class doubly_linked_list
{
private:
    Node *head{};
    Node *tail{};
    int length=0;
    void increase_length()
    {
        length++;
    }
    void decrease_length()
    {
        length--;
    }
    void delete_doubly_linked_list(Node*&temp_head)
    {
        if(temp_head->next== nullptr)
            return;
        delete_doubly_linked_list(temp_head->next);
        delete temp_head;
    }
public:
    doubly_linked_list()=default;
    doubly_linked_list(const doubly_linked_list& copy)=delete;
    doubly_linked_list&operator=(const doubly_linked_list&equal)=delete;
    ~doubly_linked_list(){

        delete_doubly_linked_list(head);
    }
    void insert_front(int value)
    {
        if(length==0)
        {
            insert_back(value);
            return;
        }
        else if(length==1)
        {
            if(tail== nullptr)
                tail=new Node{};
            Node*item=new Node{};
            item->data=value;
            item->prev= nullptr;
            item->next=head;
            head->prev=item;
            tail=head;
            head=item;
            increase_length();
            return;
        }
        else
        {
            Node*item=new Node{};
            item->data=value;
            item->prev= nullptr;
            head->prev=item;
            item->next=head;
            head=item;
            increase_length();
            return;
        }
    }
    void insert_back(int value)
    {
        if(length==0)
        {
            head=new Node{};
            head->data=value;
            head->prev= nullptr;
            head->next= nullptr;
            increase_length();
            return;
        }
        else if(length==1)
        {
            tail=new Node{};
            head->next=tail;
            tail->next= nullptr;
            tail->data=value;
            tail->prev=head;
            increase_length();
            return;
        }
        else
        {
            Node* new_item=new Node{};
            new_item->data=value;
            new_item->next= nullptr;
            new_item->prev=tail;
            tail->next=new_item;
            tail=new_item;
            increase_length();
            return;
        }
    }
    void insert_sorted(int value)
    {
        if(length==0||(tail!=nullptr&&value>=tail->data))
        {
            insert_back(value);
            return;
        }
        else if(length==1)
        {
            if(value<head->data)
                insert_front(value);
            else
                insert_back(value);
            return;
        }
        if(value<=head->data) {
            insert_front(value);
            return;
        }
        Node*item=new Node{};
        item->data=value;
        Node*before= nullptr;
        Node*after= nullptr;
        for(Node*temp=head;temp!=nullptr;temp=temp->next)
        {
            if(temp->data>value)
            {
                before=temp;
                break;
            }
        }
        after=before->prev;
        after->next=item;
        item->prev=after;
        item->next=before;
        before->prev=item;
        increase_length();
    }
    void print_forward()
    {
        for(Node*i=head;i!= nullptr;i=i->next)
            cout<<i->data<<" ";

        cout<<line;
    }
    void print_reverse()
    {
        if(length==1) {
            print_forward();
            return;
        }
        for(Node*i=tail;i!= nullptr;i=i->prev)
            cout<<i->data<<" ";
        cout<<line;
    }
};
int main() {
    khaled
    int n;
    cin>>n;
    stack<int>sk;
    queue<int>res;
    while(n--)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            int x;
            cin>>x;
            sk.push(x);
        }
        else if(a==2)
            {
            if(!sk.empty())
                sk.pop();
            }
        else
            {
             if(!sk.empty())
              res.push(sk.top());
            }
    }
    while(!res.empty())
    {
        cout<<res.front();
        cout<<line;
        res.pop();
    }
}