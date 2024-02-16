#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
template<class T>
class Vector{
    T*arr{};
    int length{};
    int cap{0};
    void extend_cap()
    {
        cap*=2;
        cap+=1;
        T *cur=new T[cap];
        for(int i=0;i<length;i++)
            cur[i]=arr[i];
        swap(cur,arr);
        delete []cur;
    }
public:
    Vector():arr(nullptr),length(0),cap(0){}
    Vector(int size)
    {
        length=size;
        arr=new T[size];
        cap=length;
    }
    T*begin()
    {
        return arr;
    }
    T*end()
    {
        return arr+length;
    }
    ~Vector()
    {
        delete []arr;
    }
    void push_back(T value)
    {
        if(arr==nullptr)
            arr=new T[1];
        if(length==cap)
        {
            extend_cap();
        }
        arr[length++]=value;
    }
    void pop_back()
    {
        if(length==0)
            return;
        length--;
    }
    T&operator[](int index)
    {
        if(index>=length||index<0)
        {
            throw invalid_argument("out of limit");
        }
        return arr[index];
    }
};
template<typename T>
struct node{
    T data{};
    node*next{};
    node*prev{};
    node(T value=-1)
    {
        this->data=value;
        this->next=this->prev=nullptr;
    }
};
template<class T>
class doubly_linked_list{
    node<T>*head{},*tail{};
    int length{};
public:
    doubly_linked_list()
    {
        this->head=this->tail=nullptr;
        length=0;
    }
    void insert(T value) {
        if (length == 0) {
            length++;
            head = new node<T>{value};
            head->next = head->prev = nullptr;
            return;
        } else if (length == 1)
        {
            length++;
            tail=new node<T>{value};
            tail->prev=head;
            head->next=tail;
            return;
        }
        length++;
        tail->next=new node<T>{value};
        tail->next->prev=tail;
        tail=tail->next;
    }
    void pop_back()
    {
        if(length==0)return;
        if(length==1){
            delete head;
            length--;
            return;
        }
        length--;
        node<T>*cur=tail;
        tail=tail->prev;
        cur->prev=nullptr;
        delete cur;
    }
    void pop_front()
    {
        if(length<=1)
        {
            pop_back();
            return;
        }
        length--;
        node<T>*cur=head;
        head=head->next;
        cur->next=nullptr;
        delete cur;
    }
    bool empty()
    {
        return length==0;
    }
    bool size()
    {
        return length==0;
    }
    T front()
    {
        if(length==0)throw runtime_error("fuck you");
        return head->data;
    }
    T back()
    {
        if(length==0)throw runtime_error("fuck you");
        return tail->data;
    }
    void insert_front(T value)
    {
        if (length == 0) {
            length++;
            head = new node<T>{value};
            head->next = head->prev = nullptr;
            return;
        } else if (length == 1)
        {
            tail=new node<T>{};
            tail=head;
            node<T>*cur=new node<T>{value};
            head=cur;
            head->next=tail;
            tail->prev=head;
            length++;
        }
        length++;
        head->prev=new node<T>{value};
        head->prev->next=head;
        head=head->prev;
    }
};
template<class T>
class Stack{
    doubly_linked_list<T>dll;
    void insert(T value)
    {
        dll.insert(value);
    }
    void pop()
    {
        dll.pop_back();
    }
    int size()
    {
        return dll.size();
    }
    bool empty()
    {
        return dll.empty();
    }
    T top()
    {
        return dll.back();
    }
};
template<class T>
class Queue{
public:
    doubly_linked_list<T>dll;
    void insert(T value)
    {
        dll.insert(value);
    }
    void pop()
    {
        dll.pop_front();
    }
    int size()
    {
        return dll.size();
    }
    bool empty()
    {
        return dll.empty();
    }
    T top()
    {
        return dll.front();
    }
};
template<typename T>
class Deque{
    doubly_linked_list<T>dll;
    void insert_back(T value)
    {
        dll.insert(value);
    }
    void insert_front(T value)
    {
        dll.insert_front(value);
    }
    void pop()
    {
        dll.pop_front();
    }
    int size()
    {
        return dll.size();
    }
    bool empty()
    {
        return dll.empty();
    }
    T top()
    {
        return dll.front();
    }
};
template<typename T>
struct tree_node{
    T data{};
    tree_node*right{},*left{};
    tree_node(T value=0)
    {
        this->data=value;
        this->left=this->right=nullptr;
    }
};
template<class T>
class tree{
    tree_node<T>*root{};
    int length=0;
    void preorder_traversal(tree_node<T>*temp)
    {
        if(!temp)return;
        cout<<temp->data<<" ";
        inorder_traversal(temp->left);
        inorder_traversal(temp->right);
    }
    void inorder_traversal(tree_node<T>*temp)
    {
        if(!temp)return;
        inorder_traversal(temp->left);
        cout<<temp->data<<" ";
        inorder_traversal(temp->right);
    }
    void postorder_traversal(tree_node<T>*temp)
    {
        if(!temp)return;
        inorder_traversal(temp->left);
        inorder_traversal(temp->right);
        cout<<temp->data<<" ";
    }
    int height(tree_node<T>*temp)
    {
        int left=0;
        int right=0;
        if(temp->left)
        {
            left+=height(temp->left);
        }
        if(temp->right)
        {
            right+=height(temp->right);
        }
        return 1+max(left,right);
    }
public:
    void insert(vector<T>values,string path)
    {
        tree_node<T>*cur=root;
        if(!cur)
        {
            root=new tree_node<T>{values[0]};
            cur=root;
        }
        for(int i=1;i<path.size();i++)
        {
            if(!cur)
            {
                root=new tree_node<T>{values[i]};
                cur=root;
                continue;
            }
            if(path[i]=='L')
            {
                if(!cur->left)
                    cur->left=new tree_node{values[i]},length++;
                cur=cur->left;
            }
            else
            {
                if(path[i]=='R')
                {
                    if(!cur->right)
                        cur->right=new tree_node{values[i]},length++;
                    cur=cur->right;
                }
            }
        }
    }
    void inorder_traversal()
    {
        inorder_traversal(root);
    }
    void preorder_traversal()
    {
        preorder_traversal(root);
    }
    void postorder_traversal()
    {
        postorder_traversal(root);
    }
    bool empty()
    {
        return length==0;
    }
    int height()
    {
        if(length==0)
            return 0;
        return height(root);
    }
};
int main() {
    khaled
    long long t;
    cin>>t;
    while(t--)
    {
        long long  x,y;
        cin>>x>>y;
        if(x*x==2*y)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<line;
    }
}