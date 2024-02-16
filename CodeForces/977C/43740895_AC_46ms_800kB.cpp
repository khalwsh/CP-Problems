#include<bits/stdc++.h>
#include<chrono>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct linked_list_node{
    int data{};
    linked_list_node*next{};
    linked_list_node(int value)
    {
        data=value;
        next=nullptr;
    }
};
class linked_list{
private:
    linked_list_node*head{};
    linked_list_node*tail{};
    int length=0;
public:
    void reverse2() {
        if (head != nullptr) {
            reverseRecursive(nullptr, head);
        }
    }
private:
    void reverseRecursive(linked_list_node* prev, linked_list_node* curr) {
        if(curr==nullptr)
            return;
        if (curr->next == nullptr) {
            head = curr;
            curr->next = prev;
        } else {
            reverseRecursive(curr, curr->next);
            curr->next = prev;
        }
    }
public:
    //insert delete find reverse
    void insert(int value)
    {
        if(!length)
        {
            head=new linked_list_node(value);
            length++;
            head->next=nullptr;
        }
        else if(length==1)
        {
            tail=new linked_list_node{value};
            head->next=tail;
            tail->next=nullptr;
            length++;
        }
        else
        {
            //2 3 2 -->2
            tail->next=new linked_list_node(value);
            tail=tail->next;
            length++;
        }
    }
    void print()
    {
        linked_list_node*temp=head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<line;
    }
    bool find(int value)
    {
        //linear search
        linked_list_node*temp=head;
        while(temp)
        {
            if(temp->data==value)
                return true;
            temp=temp->next;
        }
        return false;
    }
    void reverse_iterative()
    {
        linked_list_node*prev=nullptr;
        linked_list_node*cur=head;
        tail=head;
        while(cur)
        {
            linked_list_node*save=cur->next;
            cur->next=prev;
            prev=cur;
            cur=save;
        }
        head=prev;
    }
    linked_list_node* reverse(linked_list_node* node)
    {
        if (node == nullptr)
            return nullptr;
        if (node->next == nullptr) {
            head = node;
            return node;
        }
        linked_list_node* node1 = reverse(node->next);
        node1->next = node;
        node->next = nullptr;
        return node;
    }
    void reverse_recursive()
    {
        tail=reverse(head);
        tail->next=nullptr;
    }
    void erase(int value)
    {
        if(length==0)
            return;
        else if(head->data==value)
        {
            linked_list_node*temp=head;
            head=head->next;
            temp->next=nullptr;
            delete temp;
            temp=nullptr;
            length--;
            return;
        }
        if(!find(value))
            return;
        linked_list_node*prev=nullptr;
        linked_list_node*cur=head;
        while(cur)
        {
            if(cur->data==value)
                break;
            prev=cur;
            cur=cur->next;
        }
        prev->next=cur->next;
        cur->next=nullptr;
        delete cur;
        length--;
    }
};
class sorting{
public:
    void my_swap(int &a,int &b)
    {
        a^=b;// a has a^b value stored in it
        b^=a;//now b^a--->from the last line b^a^b which will be a cause of the property so b has value of a
        a^=b;//now a has value of a^b then make a^b -->b has value of a from last operation then a^a^b equal to b
        //take by ref because I want the change being done actually on them not a copy
        //i will preform xor swaping it's much more efficent
        //nice property about xor if a^a the result equal zero
        //swaping done effiecnt because xor is much more faster than making a temp variable and swap
    }
    void selection_sort(int arr[],int size)
    {
        //the array is sent by refernce so the sorting is being acually done in the data it's self
        //the array couldn't be passed by value
        //this algorithm of sorting making n rounds in every round choose the ith smallest element and place it in it's right postion
        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                if(arr[j]<arr[i])
                    my_swap(arr[j],arr[i]);
            }
        }
        //time complexity is o(n^2)
        //space complexity is o(1)
        //this algorithm isn't efficent :)
    }
    void bubble_sort(int arr[],int size)
    {
        //the array is sent by refernce so the sorting is being acually done in the data it's self
        //the array couldn't be passed by value
        //this algorithm of sorting making n rounds in every round if there is two consegative elements which are in wrong postion from each other
        //it makes them in right order
        for(int i=0;i<size;i++)
        {
            for(int j=0;j+1<size;j++)
            {
                if(arr[j]>arr[j+1])
                    my_swap(arr[j],arr[j+1]);
            }
        }
        //time complexity is o(n^2)
        //space complexity is o(1)
        //this algorithm isn't effcient :)
    }
    void insertion_sort(int arr[],int size)
    {
        //the array is sent by refernce so the sorting is being acually done in the data it's self
        //the array couldn't be passed by value
        //this algorithm of sorting is insert the element in it's right postion in a new array or in the same array
        for(int i=0;i<size;i++)//o(n(1+1+n(1+1))//o(2n^2+2n)
        {
            int pointer=i;
            int j=i-1;
            while(j>=0&&arr[pointer]<arr[j])
            {
                my_swap(arr[pointer--],arr[j]);
                j--;
            }
        }
        //best case omega(n)
        //time complexity is o(n^2)
        //space complexity is o(1)
        //this algorithm isn't effcient :)
    }
    void merge(int arr[],int left,int mid,int right)
    {
        int siz1=mid-left+1;
        int siz2=right-mid;
        int arr1[siz1];
        int arr2[siz2];
        for(int i=0;i<siz1;i++)
            arr1[i]=arr[left+i];
        for(int i=0;i<siz2;i++)
            arr2[i]=arr[mid+i+1];
        int i=0,j=0,k=left;
        while(i<siz1&&j<siz2)
        {
            if(arr1[i]<arr2[j])
                arr[k++]=arr1[i++];
            else
                arr[k++]=arr2[j++];
        }
        while(i<siz1)
            arr[k++]=arr1[i++];
        while(j<siz2)
            arr[k++]=arr2[j++];
    }
    void merge_sort(int arr[],int left,int right)
    {
        if(left>=right)
            return;
        int mid=left+(right-left)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
};
class my_stack{
private:
    int length=0;
    int capcity=0;
    int *arr{};
    int top=-1;
    void extend_cap()
    {
        capcity*=2;
        capcity++;
        int *temp=new int[capcity];
        for(int i=0;i<length;i++)
            temp[i]=arr[i];
        delete []arr;
        arr=new int[capcity];
        for(int i=0;i<length;i++)
            arr[i]=temp[i];
        delete[]temp;
    }
public:
    void push(int value)
    {
        if(length==capcity)
            extend_cap();
        if(arr==nullptr)
            arr=new int[capcity];
        arr[++top]=value;
        length++;
    }
    int front()
    {
        if(top>=0&&arr!=nullptr)
           return arr[top];
        return -1;
    }
    void pop()
    {
        if(top==-1)
            return;
        top--;
        length--;
    }
    bool empty()
    {
        return top==-1;
    }
};
class my_queue{
private:
    int length=0;
    int capcity=0;
    int *arr{};
    int front=0;
    void extend_cap()
    {
        capcity*=2;
        capcity++;
        int *temp=new int[capcity];
        if(arr==nullptr)
            arr=new int[capcity];
        for(int i=0;i<length;i++)
            temp[i]=arr[i];
        delete []arr;
        arr=new int[capcity];
        for(int i=0;i<length;i++)
            arr[i]=temp[i];
        delete[]temp;
    }
public:
    void push(int value)
    {
        if(length==capcity)
            extend_cap();
        if(arr==nullptr)
            arr=new int[capcity];
        arr[length++]=value;
    }
    void pop()
    {
        front++;
    }
    int top()
    {
        if(front==-1)
          return -1;
        return arr[front];
    }
    bool empty()
    {
        return front==length;
    }
};
class searching{
public:
    static bool linear_search(const int arr[],int siz,int target)
    {
        for(int i=0;i<siz;i++)
            if(target==arr[i])
                return true;
        return false;
    }
    static bool rec_linear_search(int index,int arr[],int siz,int target)
    {
        if(siz==index)
            return false;
        if(arr[index]==target)
            return true;
        return rec_linear_search(index+1,arr,siz,target);
    }
    static bool binary_search(const int arr[],int value,int siz,int target)
    {
        int left=0;
        int right=siz;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(arr[mid]==target)
                return true;
            else if(arr[mid]>target)
                right=mid-1;
            else
                left=mid+1;
        }
        return false;
    }
    static bool rec_binary_search(int arr[],int siz,int target,int start,int end)
    {
        if(start>end)
            return false;
        int mid=start+(end-start)/2;
        if(arr[mid]==target)
            return true;
        else if(arr[mid]>target)
            return rec_binary_search(arr,siz,target,start,mid-1);
        else
            return rec_binary_search(arr,siz,target,mid+1,end);
    }
};
struct binary_search_node{
    int data{};
    binary_search_node*right,*left;
    binary_search_node()
    {
        this->data=0;
        this->left=this->right=nullptr;
    }
    binary_search_node(int value)
    {
        this->data=value;
        this->left=this->right=nullptr;
    }
};
class binary_search_tree{
private:
    binary_search_node*root{};
    void insert_recursive(binary_search_node*node,int value)
    {
        if(!root)
        {
            root=new binary_search_node{value};
            return;
        }
        if(node->data==value)
            return;
        if(value>node->data)
        {
            if(node->right)
                insert_recursive(node->right,value);
            else
                node->right=new binary_search_node{value};
        }
        else
        {
            if(node->left)
                insert_recursive(node->left,value);
            else
                node->left=new binary_search_node(value);
        }
    }
    void inorder_traversal(binary_search_node*node)
    {
        if(!node)
            return;
        inorder_traversal(node->left);
        cout<<node->data<<" ";
        inorder_traversal(node->right);
    }
    bool find_rec(binary_search_node*temp,int value)
    {
        if(!temp)
            return false;
        bool res=temp->data==value;
        if(temp->data>value)
            res=res||find_rec(temp->left,value);
        else if(temp->data<value)
            res=res||find_rec(temp->right,value);
        return res;
    }
public:
    binary_search_tree()
    {
        root=nullptr;
    }
    binary_search_tree(int value)
    {
        root=new binary_search_node{value};
    }
    void insert(int value)
    {
        if(root==nullptr)
        {
            root=new binary_search_node{value};
            return;
        }
        binary_search_node*temp=root;
        while(temp)
        {
            if(temp->data==value)
                return;
            if(temp->data>value)
            {
                if(temp->left)
                    temp=temp->left;
                else {
                    temp->left = new binary_search_node{value};
                    return;
                }
            }
            else
            {
                if(temp->right)
                    temp=temp->right;
                else {
                    temp->right = new binary_search_node{value};
                    return;
                }
            }
        }
    }
    void insert_recursive(int value)
    {
        insert_recursive(root,value);
    }
    void print()
    {
        inorder_traversal(root);
    }
    bool find(int value)
    {
        binary_search_node*node=root;
        while(node)
        {
            if(node->data==value)
                return true;
            if(node->data>value)
                node=node->left;
            else
                node=node->right;
        }
        return false;
    }
    bool find_rec(int value)
    {
        return find_rec(root,value);
    }
};
signed main() {
    khaled
    int n;
    int k;
    cin>>n>>k;
    vector<int>v(n);
    for(auto &val:v)
        cin>>val;
    sort(v.begin(),v.end());
    if(k==n) { cout << v[k - 1]  << line; }
    else if(k==0)
    {
        if(v[k]==1)
            cout<<-1;
        else
            cout<<1;

    }
    else
    {
        if(v[k-1]==v[k])
            cout<<-1;
        else
            cout<<v[k-1];
        cout<<line;
    }
}