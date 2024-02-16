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
    void size()
    {
        return dll.size();
    }
    void empty()
    {
        return dll.empty();
    }
    void top()
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
    void size()
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
    void size()
    {
        return dll.size();
    }
    void empty()
    {
        return dll.empty();
    }
    void top()
    {
        return dll.front();
    }
};
bool valid(int i,int j,int n,int m)
{
    return i>=0&&i<n&&j>=0&&j<m;
}
bool work=true;
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
void influence(int row,int col,int n,int m,vector<vector<char>>&v)
{

    v[row][col]='#';
    for(int l=0;l<4;l++)
    {
        int cur_row=row+dx[l];
        int cur_col=col+dy[l];
        if(valid(cur_row,cur_col,n,m)&&(v[cur_row][cur_col]=='G'||cur_row==n-1&&cur_col==m-1))
        {
            work=false;
            return;
        }
        else if(valid(cur_row,cur_col,n,m)&&v[cur_row][cur_col]=='.')
        {
            v[cur_row][cur_col]='#';
        }
    }
}
bool done(int row,int col,int n,int m,vector<vector<char>>&v,vector<vector<bool>>&vis)
{
    vis[row][col]=true;
    Queue<pair<int,int>>q;
    bool ha=false;
    q.insert(make_pair(row,col));
    while(!q.empty())
    {
        row=q.top().first;
        col=q.top().second;
        q.pop();
        if(row==n-1&&col==m-1) {
            ha = true;
            break;
        }
        for(int l=0;l<4;l++) {
            int cur_row = row + dx[l];
            int cur_col = col + dy[l];
            if(valid(cur_row,cur_col,n,m)&&v[cur_row][cur_col]!='#'&&!vis[cur_row][cur_col])
            {
                v[cur_row][cur_col]='.';
                vis[cur_row][cur_col]=true;
                q.insert(make_pair(cur_row,cur_col));
            }
        }
    }
    return ha;
}
int main() {
    khaled
    int t;
    cin>>t;
    while(t--) {
        int n;
        work=true;
        int m;
        cin >> n >> m;
        vector<vector<char>> v(n, vector<char>(m));
        for (auto &val: v)for (auto &i: val)cin >> i;
        int c=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 'B') {
                    influence(i, j, n, m, v);
                }
                else if(v[i][j]=='G')
                    c++;
            }
        }
        if (!work&&c!=0)
            cout << "NO" << line;
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (v[i][j] == 'G') {
                        vector<vector<bool>> vis(n, vector<bool>(m, false));
                        if (!done(i, j, n, m, v, vis)) {
                            work = false;
                            break;
                        }
                    }
                }
                if (!work)
                    break;
            }
            if (!work&&c!=0)
                cout << "NO";
            else
                cout << "YES";
            cout << line;
        }
    }
}