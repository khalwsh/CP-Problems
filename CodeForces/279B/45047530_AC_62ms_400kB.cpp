#include<bits/stdc++.h>
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
long long fast_power(long long base,long long power,long long m=8e18) {
    //get power in log(n) and you can set mod to adjust with the output
    if (power == 1 || power == 0)
        return base * power + (!power);
    long long res = (fast_power(base, power / 2, m) % m) % m;
    if (power & 1)
        return (((((base % m) * (res % m)) % m) * (res % m)) % m) % m;
    else
        return ((res % m) * (res % m)) % m;
}
long long gcd_ecludien_algorthim(int a,int b,int &x,int &y)
{
        //a*x+b*y=gcd(a,b)
        /*this function return gcd of (a,b)
          and update the value of x,y to achieve
          the ecludien equation
          ax+by=gcd(a,b);
          */
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    long long d=gcd_ecludien_algorthim(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return d;
}
vector<bool> sieve_of_eratosthenes(int sz)
{
    //return the numbers which not prime in the range from 2 to size
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
struct node{
    int data;
    node *next{};
    explicit node(int data=0)
    {
        this->data=data;
    }
};
class linked_list
{
private:
    node *head;
    node *tail;
    int length;
    int size()const
    {
        return length;
    }
    void delete_linked_list(node*&temp_head)
    {
        if(temp_head== nullptr)
            return;
        delete_linked_list(temp_head->next);
        delete temp_head;
    }
public:
    linked_list()
    {
        head=nullptr;
        tail=nullptr;
        length=0;
    }
    linked_list(int value1,int value2)
    {
        head=new node{};
        tail=new node{};
        head->data=value1;
        tail->data=value2;
        head->next=tail;
        tail->next=nullptr;
        length=2;
    }
    ~linked_list()
    {
        delete_linked_list(head);
    }
    void insert_back(int value)
    {
        if(size()==0)
        {
            length++;
            head=new node{};
            head->data=value;
            head->next=tail;
        }
        else if(size()==1)
        {
            length++;
            tail=new node{};
            tail->data=value;
            head->next=tail;
            tail->next=nullptr;
        }
        else
        {
            node*new_node=new node{};
            new_node->data=value;
            new_node->next=nullptr;
            tail->next=new_node;
            swap(tail,new_node);
            length++;
        }
    }
    void print_linked_list()
    {
        node*temp_head=new node{};
        temp_head=head;
        while(temp_head!=nullptr)
        {
            cout<<temp_head->data<<" ";
            temp_head=temp_head->next;
        }
        cout<<line;
        delete temp_head;
    }
    void insert_front(int value)
    {
        if(size()==0)
        {
            length++;
            head=new node{};
            head->data=value;
            head->next=nullptr;
        }
        else if(size()==1)
        {
            tail=new node{};
            tail->data=value;
            tail->next=head;
            swap(tail,head);
            length++;
        }
        else
        {
            node*new_node=new node{};
            new_node->data=value;
            new_node->next=head;
            swap(new_node,head);
            length++;
        }
    }
    linked_list&operator=(linked_list ls)=delete;
    linked_list(const linked_list &other)=delete;
    void delete_front()
    {
        node*temp_node=new node{};
        temp_node=head;
        temp_node=temp_node->next;
        delete head;
        head=temp_node;
        delete temp_node;
        length--;
    }
    bool is_same(linked_list&ls)
    {
        if(length!=ls.size())
            return false;
        else
        {
            node*temp_head1=new node{};
            node*temp_head2=new node{};
            temp_head1=head;
            temp_head2=ls.head;
            int temp_length=length;
            while(temp_length--)
            {
                if(temp_head1->data!=temp_head2->data)
                {
                    delete temp_head1;
                    delete temp_head2;
                    return false;
                }
                temp_head1=temp_head1->next;
                temp_head2=temp_head2->next;
            }
            delete temp_head1;
            delete temp_head2;
            return true;
        }
    }
    node*get_nth_from_front(int index)
    {
        node*temp_head=head;
        index--;//1 base
        if(index>=size())
            return nullptr;
        int counter=0;
        while(temp_head!=nullptr)
        {
            if(index==counter)
                return temp_head;
            temp_head=temp_head->next;
            counter++;
        }
        return nullptr;
    }
    node*get_nth_from_back(int index)
    {
        return get_nth_from_front(size()-index+1);
    }
    long long get_element_summation()
    {
        node*temp_head=new node{};
        temp_head=head;
        long long summation=0;
        while(temp_head!=nullptr)
        {
           summation+=(long long)temp_head->data ;
           temp_head=temp_head->next;
        }
        delete temp_head;
        return summation;
    }

};
int main() {
    khaled
    int n;
    int t;
    cin>>n>>t;
    vector<int>v(n);
    for(auto &val:v)
        cin>>val;
    int summation=0;
    int left=0,right=0;
    int my_max=0;
    while(true) {
        if(right==n)
            break;
        summation+=v[right];
         if(summation>t)
        {
            while(summation>t)
            {
                summation-=v[left];
                left++;
            }
        }
        right++;

        my_max=max(right-left,my_max);
    }
    cout<<my_max;
}