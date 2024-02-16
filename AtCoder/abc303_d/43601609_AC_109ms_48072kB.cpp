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
    int size()
    {
        return length;
    }
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
    node<T>*first()
    {
        return head;
    }
    void insert(T value) {
        if (length == 0) {
            length++;
            head = new node<T>{value};
            head->next = head->prev = nullptr;
            tail=head;
            return;
        } else if (length == 1)
        {
            length++;
            tail=nullptr;
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
public:
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
public:
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
    tree_node<T>*construct(deque<T>&preorder,deque<T>&inorder,int start,int end)
    {
        if(start>end)return nullptr;
        tree_node<T>*temp=new tree_node<T>{preorder.front()};
        preorder.pop_front();
        if(start==end)return temp;
        for(int i=start;i<=end;i++)
        {
            if(temp->data==inorder[i])
            {
                temp->left=construct(preorder,inorder,start,i-1);
                temp->right=construct(preorder,inorder,i+1,end);
                break;
            }
        }
        return temp;
    }
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
    tree(deque<T>&pre,deque<T>&inorder)
    {
        root= construct(pre,inorder,0,pre.size()-1);
        length=(int)pre.size();
    }
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
template<class T>
class binary_search_tree{
private:
    tree_node<T>*root{};
    int length{};
    void insert(tree_node<T>*temp,T value)
    {
        if(!temp)
        {
            return;
        }
        if(value==temp->data)return;
        else if(value<temp->data)
        {
            if(temp->left)
                insert(temp->left,value);
            else
                temp->left=new tree_node<T>{value};
        }
        else
        {
            if(temp->right)
                insert(temp->right,value);
            else
                temp->right=new tree_node<T>{value};
        }
    }
    void print(tree_node<T>*temp)
    {
        if(!temp)
            return;
        print(temp->left);
        cout<<temp->data<<" ";
        print(temp->right);
    }
    tree_node<T>*find(T value)
    {
        tree_node<T>*temp=root;
        while(temp)
        {
            if(temp->data==value)
                break;
            else if(temp->data>value)
                temp=temp->left;
            else
                temp=temp->right;
        }
        return temp;
    }
    tree_node<T>*find_parent(T value)
    {
        tree_node<T>*temp=root;
        tree_node<T>*prev=nullptr;
        while(temp)
        {
            if(temp->data==value)
                break;
            else if(temp->data>value)
               prev=temp,temp=temp->left;
            else
               prev=temp,temp=temp->right;
        }
        return prev;
    }
    void connect_parent_to_grand_child(tree_node<T>*parent,tree_node<T>*child)
    {
        if(child->left)
        {
            if(parent->left==child)
                parent->left=child->left;
            else
                parent->right=child->left;
        }
        else
        {
            if(parent->left==child)
                parent->left=child->right;
            else
                parent->right=child->right;
        }
        child->left=child->right=nullptr;
    }
    tree_node<T>*get_succeor_small_right(tree_node<T>*temp)
    {
        tree_node<T>*cur=temp;
        while(cur->left)cur=cur->left;
        return cur;
    }
public:
    binary_search_tree&copy(const binary_search_tree&co)=delete;
    binary_search_tree&operator=(const binary_search_tree&co)=delete;
    binary_search_tree():root(nullptr),length(0){}
    binary_search_tree(T value)
    {
        this->root=new tree_node<T>{value};
        length=1;
    }
    void insert(T value)
    {
        if(!root)
        {
            root=new tree_node(value);
            length=1;
            return;
        }
        insert(root,value);
        length++;
    }
    void print()
    {
        if(!root)
            return;
        print(root);
        cout<<line;
    }
    bool empty()
    {
        return root==nullptr;
    }
    void erase(T value)
    {
        tree_node<T>*to_del=find(value);
        if(!to_del||!length)
            return;
        if(!to_del->left&&!to_del->right)//has no children just erase
        {
            tree_node<T>*prev= find_parent(value);
            if(!prev)
            {
                delete to_del;
                to_del=nullptr;
                root=nullptr;
                length--;
                return;
            }
            length--;
            if(prev->left==to_del)
                prev->left=nullptr;
            else
                prev->right=nullptr;
            delete to_del;
            to_del=nullptr;
            return;
        }
        else if(!to_del->left||!to_del->right)//only one child connect parent to grand child
        {
            tree_node<T>*prev= find_parent(value);
            if(!prev)
            {
                if(to_del->left)
                    root=root->left,to_del->left=nullptr;
                else
                    root=root->right,to_del->right=nullptr;
                delete to_del;
                to_del=nullptr;
                length--;
                return;
            }
            length--;
            connect_parent_to_grand_child(prev,to_del);
            to_del->right=to_del->left=nullptr;
            delete to_del;
            to_del=nullptr;
            return;
        }
        else //the normal case the node has two children
        {
            tree_node<T>*temp=get_succeor_small_right(to_del->right);
            int toto=temp->data;
            erase(temp->data);
            to_del->data=toto;
        }
    }
    int size()
    {
        return length;
    }
};
template<typename T>
class min_heap{
    T*arr{};
    int size{0};
    int cap{0};
    void extend_cap()
    {
        cap*=2;
        cap+=1;
        T *cur=new T[cap];
        for(int i=0;i<size;i++)
            cur[i]=arr[i];
        swap(cur,arr);
        delete []cur;
    }
    void hepify_up(int index)
    {
        int par=parent(index);
        if(par==-1||arr[par]<=arr[index])
            return;
        swap(arr[par],arr[index]);
        hepify_up(par);
    }
    int left_child(int pos)
    {
        return (2*pos+1>=size)?-1:2*pos+1;
    }
    int right_child(int pos)
    {
        return (2*pos+2>=size)?-1:2*pos+2;
    }
    int parent(int pos)
    {
        return (pos==0)?-1:(pos-1)/2;
    }
    void hepify_down(int index)
    {
        int child_pos= left_child(index);
        int r= right_child(index);
        if(child_pos==-1)
            return;
        if(r!=-1&&arr[r]<arr[child_pos])
            child_pos= r;
        if(arr[index]>arr[child_pos])
            swap(arr[index],arr[child_pos]), hepify_down(child_pos);
    }
public:
    min_heap()
    {
        this->arr=nullptr;
        this->size=0;
    }
    void push(T value)
    {
        if(size==cap)
            extend_cap();
        arr[size++]=value;
        hepify_up(size-1);
    }
    void pop()
    {
        if(size==0)
            return;
        swap(arr[0],arr[size-1]);
        size--;
        hepify_down(0);
    }
    bool empty()
    {
        return size==0;
    }
    T top()
    {
        return arr[0];
    }
};
template<class T>
class max_heap{
    T*arr{};
    int size{0};
    int cap{0};
    void extend_cap()
    {
        cap*=2;
        cap+=1;
        T *cur=new T[cap];
        for(int i=0;i<size;i++)
            cur[i]=arr[i];
        swap(cur,arr);
        delete []cur;
    }
    void hepify_up(int index)
    {
        int par=parent(index);
        if(par==-1||arr[par]>=arr[index])
            return;
        swap(arr[par],arr[index]);
        hepify_up(par);
    }
    int left_child(int pos)
    {
        return (2*pos+1>=size)?-1:2*pos+1;
    }
    int right_child(int pos)
    {
        return (2*pos+2>=size)?-1:2*pos+2;
    }
    int parent(int pos)
    {
        return (pos==0)?-1:(pos-1)/2;
    }
    void hepify_down(int index)
    {
        int child_pos= left_child(index);
        int r= right_child(index);
        if(child_pos==-1)
            return;
        if(r!=-1&&arr[r]>arr[child_pos])
            child_pos= r;
        if(arr[index]<arr[child_pos])
            swap(arr[index],arr[child_pos]), hepify_down(child_pos);
    }
public:
    max_heap()
    {
        this->arr=nullptr;
        this->size=0;
    }
    void push(T value)
    {
        if(size==cap)
            extend_cap();
        arr[size++]=value;
        hepify_up(size-1);
    }
    void pop()
    {
        if(size==0)
            return;
        swap(arr[0],arr[size-1]);
        size--;
        hepify_down(0);
    }
    bool empty()
    {
        return size==0;
    }
    T top()
    {
        return arr[0];
    }
};
#define int long long
signed main() {
    khaled
    int x,y,z;//press a,press a with shift,press capslock
    cin>>x>>y>>z;
    string s;
    cin>>s;
    int n=(int)s.size();
    vector<vector<vector<int>>>vis(n,vector<vector<int>>(2,vector<int>(2,INT64_MAX)));//0 visited with the first case,1 for visited with the second,
    //vis[index][x||y][capslock||not]
    priority_queue<pair<int,pair<int,bool>>,vector<pair<int,pair<int,bool>>>,greater<>>pq;//the cost and index
    pq.push({0,{-1,0}});
    while(!pq.empty())
    {
        int node=pq.top().second.first;
        bool state=pq.top().second.second;
        long long cost=pq.top().first;
        pq.pop();
        if(node==n-1)
            break;
        if(state==0) {
            if (vis[node + 1][0][0] > cost + x && s[node + 1] == 'a') {
                pq.push({cost + x, {node + 1, 0}});
                vis[node + 1][0][0] = cost + x;
            }
            if (vis[node + 1][0][1] > cost + x + z && s[node + 1] == 'A') {
                pq.push({cost + x + z, {node + 1, 1}});
                vis[node + 1][0][1] = cost + x + z;
            }
            if (vis[node + 1][1][0] > cost + y && s[node + 1] == 'A') {
                pq.push({cost + y, {node + 1, 0}});
                vis[node + 1][1][0] = cost + y;
            }
            if (vis[node + 1][1][1] > cost + y + z && s[node + 1] == 'a') {
                pq.push({cost + y + z, {node + 1, 1}});
                vis[node + 1][1][1] = cost + y + z;
            }
        }
        else if(state==1)
        {
            if (vis[node + 1][0][0] > cost + x+z && s[node + 1] == 'a') {
                pq.push({cost + x+z, {node + 1, 0}});
                vis[node + 1][0][0] = cost + x+z;
            }
            if (vis[node + 1][0][1] > cost + x  && s[node + 1] == 'A') {
                pq.push({cost + x , {node + 1, 1}});
                vis[node + 1][0][1] = cost + x ;
            }
            if (vis[node + 1][1][0] > cost + y+z && s[node + 1] == 'A') {
                pq.push({cost + y+z, {node + 1, 0}});
                vis[node + 1][1][0] = cost + y+z;
            }
            if (vis[node + 1][1][1] > cost + y  && s[node + 1] == 'a') {
                pq.push({cost + y , {node + 1, 1}});
                vis[node + 1][1][1] = cost + y;
            }
        }
    }
    cout<<min({vis[n-1][0][1],vis[n-1][1][0],vis[n-1][1][1],vis[n-1][0][0]})<<line;
}