/*#include<bits/stdc++.h>
#define line '\n'
#define khaled ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
using namespace std;
struct node
{
    int data;
    node *next;
    node()
    {
        this->data=0;
        this->next=nullptr;
    }
    node(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};
int main() {
     khaled
    node*node1=new node{20};
     node*node2=new node{30};
     node*node3=new node{40};

     node1->next=node2;
     node2->next=node3;
    (*node3).next=nullptr;
    cout<<node1->next->next->data;


}*/
#include<bits/stdc++.h>
#define line '\n'
#define khaled ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
using namespace std;
int mod;
long long calcualte(long long a,long long b);
 long long mod_expontential( long long a, long long b);
int main() {
    khaled
     long long A,B,C;
    cin>>A>>B>>C;
    if(A%10==0||A%10==1||A%10==5||A%10==6)
        cout<<A%10;
    else {
        if (A % 10 == 9 || A % 10 == 4)
            mod = 2;
        else if (A % 10 == 2 || A % 10 == 3 || A % 10 == 7 || A % 10 == 8)
            mod = 4;
        cout << calcualte(A % 10, mod_expontential(B, C)) % 10;
    }
}
 long long mod_expontential( long long a, long long b)
{
     long long res=1;
    while(b>0)
    {
        if(b&1)
            res=((res%mod)*(a%mod))%mod;
        a=((a%mod)*(a%mod))%mod;
        b/=2;
    }
    return res;
}
long long calcualte(long long a,long long b)
{
    if (a == 0)
        return 0;
    if (a == 1)
        return a;
    if (a == 2)
    {
        if (b % 4 == 1)
            return 2;
        if (b % 4 == 2)
            return 4;
        if (b % 4 == 3)
            return 8;
        if (b % 4 == 0)
            return 6;
    }
    if (a == 3)
    {
        if (b % 4 == 0)
            return 1;
        if (b % 4 == 1)
            return 3;
        if (b % 4 == 2)
            return 9;
        if (b % 4 == 3)
            return 7;
    }
    if (a == 4)
    {
        if (b % 2 == 0)
            return 6;
        else
            return 4;
    }
    if (a == 5 || a == 6)
    {
        return a;
    }
    if (a == 9)
    {
        if (b % 2 == 0)
            return 1;
        else
            return 9;
    }
    if (a == 7)
    {
        if (b % 4 == 0)
            return 1;
        if (b % 4 == 1)
            return 7;
        if (b % 4 == 2)
            return 9;
        if (b % 4 == 3)
            return 3;
    }
    if (a == 8)
    {
        if (b % 4 == 1)
            return 8;
        if (b % 4 == 2)
            return 4;
        if (b % 4 == 3)
            return 2;
        if (b % 4 == 0)
            return 6;
    }
}
