#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
class binary_search_tree{
private:
    int data{0};
    binary_search_tree* left{},*right{};
    int length{};
    void complete(vector<int>&v)
    {
        if(left)
            left->complete(v);
        v.emplace_back(data);
        if(right)
            right->complete(v);
    }
    bool sorted(vector<int>&v)
    {
        for(int i=0;i<v.size()-1;i++)
            if(v[i+1]<v[i])
                return false;
        return true;
    }
    void make_min(deque<int>&dq_optimize,deque<int>&orginal_preorder,int value)
    {
        for(auto &val:orginal_preorder)
            if(val<value)
                dq_optimize.push_back(val);
    }
    void make_max(deque<int>&dq_optimize,deque<int>&orginal_preorder,int value)
    {
        for(auto &val:orginal_preorder)
            if(val>value)
                dq_optimize.push_back(val);
    }
    pair<binary_search_tree*,binary_search_tree*>parent_and_child(int value)
    {
        binary_search_tree*parent=nullptr;
        binary_search_tree*child=this;
        pair<binary_search_tree*,binary_search_tree*>res{nullptr,nullptr};
        while(child)
        {
            if(value==child->data)
            {
                res=make_pair(parent,child);
                child=child->right;
            }
            else if(value>child->data)
            {
                parent=child;
                child=child->right;
            }
            else
            {
                parent=child;
                child=child->left;
            }
        }
        return res;
    }
    binary_search_tree* get_min_node_of_my_right()
    {
        binary_search_tree*res=this;
        while(res->left)
            res=res->left;
        return res;
    }
    binary_search_tree* get_max_node_of_my_left()
    {
        binary_search_tree*res=this;
        while(res->right)
            res=res->right;
        return res;
    }
public:
    deque<int> next_greater_elements(deque<int>&v)
    {
        stack<int>sk;
        for(int i=0;i<(int)v.size();i++)
        {
            while(!sk.empty()&&v[i]>v[sk.top()])
            {
                v[sk.top()]=i;
                sk.pop();
            }
            sk.push(i);
        }
        while(!sk.empty())
        {
            v[sk.top()]=(int)v.size();
            sk.pop();
        }
        return v;
    }
    void erase(int value)
    {
        pair<binary_search_tree*,binary_search_tree*>find= parent_and_child(value);
        //first is the parent second is the child;
        if(find.second==nullptr||find.first== nullptr) {
            if(find.second== nullptr)
               return;
            else
            {
                //handle root deletion
            }
            return;
        }
        if(find.second->right&&find.second->left)
        {
            //two children
            binary_search_tree*deleted=find.second->right->get_min_node_of_my_right();
            pair<binary_search_tree*,binary_search_tree*>parent_deleted= parent_and_child(deleted->data);
            find.second->data=deleted->data;
            deleted->left=nullptr;
            if(parent_deleted.first->right==parent_deleted.second)
                parent_deleted.first->right=parent_deleted.second->right;
            else
                parent_deleted.first->left=parent_deleted.second->right;
            parent_deleted.second->left=parent_deleted.second->right=nullptr;
            delete parent_deleted.second;
            parent_deleted.second=nullptr;
        }
        else if(find.second->right&&!find.second->left||find.second->left&&!find.second->right)
        {
            //has one child right or left doesn't matter;
            if(find.second->right&&find.first)
            {
                if(find.first->left==find.second)
                    find.first->left=find.second->right;
                else
                    find.first->right=find.second->right;
            }
            else
            {
                if(find.first) {
                    if (find.first->left == find.second)
                        find.first->left = find.second->left;
                    else
                        find.first->right = find.second->left;
                }
            }
            if(!find.first)
            {
                if(find.second->right) {
                    this->data = find.second->right->data;
                    this->right = find.second->right->right;
                    this->left = find.second->right->left;
                }
                else
                {
                    this->data = find.second->left->data;
                    this->right = find.second->left->right;
                    this->left = find.second->left->left;
                }
            }
            find.second->right= nullptr;
            find.second->left=nullptr;
            delete find.second;
            find.second=nullptr;

        }
        else
        {
            //has no child just delete
            if(find.first->right==find.second)
                find.first->right= nullptr;
            else
                find.first->left=nullptr;
            delete find.second;
            find.second=nullptr;
        }
    }
    void clear()
    {
        if(left)
            delete left,left= nullptr;
        if(right)
            delete right,right= nullptr;
    }
    ~binary_search_tree()
    {
        clear();
    }
    binary_search_tree(deque<int>&preorder)
    {
        binary_search_tree*root=build_binary_search_tree_from_preorder(preorder);
        this->data=root->data;
        this->left=root->left;
        this->right=root->right;
    }
    binary_search_tree(deque<int>&preorder,deque<int>&inorder,int start=0,int end=-10)
    {
       auto root=build_binary_search_tree_from_preorder_and_inorder(preorder,inorder);
       this->data=root->data;
       this->left=root->left;
       this->right=root->right;
    }
    binary_search_tree* build_binary_search_tree_from_preorder_and_inorder(deque<int>&preorder,deque<int>&inorder,int start=0,int end=-10)
    {
        if(end==-10)
        {
            end=(int)preorder.size();
        }
        if(start>end||preorder.empty())
            return nullptr;
        int first=preorder.front();
        int mid= (int)(lower_bound(inorder.begin(),inorder.end(),first)-inorder.begin());
        preorder.pop_front();
        binary_search_tree*north= build_binary_search_tree_from_preorder_and_inorder(preorder,inorder,start,mid-1);
        binary_search_tree*south= build_binary_search_tree_from_preorder_and_inorder(preorder,inorder,mid+1,end);
        auto root=new binary_search_tree(first,north,south);
        return root;
    }
    binary_search_tree* build_binary_search_tree_from_preorder(deque<int>&dq)
    {
        deque<int>ddq;
        make_min(ddq,dq,dq.front());
        binary_search_tree*l= nullptr,*r= nullptr;
        if(!ddq.empty())
            l= build_binary_search_tree_from_preorder(ddq);
        deque<int>dqdq;
        make_max(dqdq,dq,dq.front());
        if(!dqdq.empty())
            r= build_binary_search_tree_from_preorder(dqdq);
        auto root=new binary_search_tree(dq.front(), l, r);
        dq.pop_front();
        return root;
    }
    int max()
    {
        binary_search_tree*tt=this;
        while(tt&&tt->right)
            tt=tt->right;
        return tt->data;
    }
    bool find_chain(vector<int>&path,int target)
    {
        bool it=target==this->data;
        path.emplace_back(this->data);
        if(left&&target<this->data)
            return left->find_chain(path,target);
        if(right&&target>data)
            return right->find_chain(path,target);
        return it;

    }
    pair<binary_search_tree*,binary_search_tree*> find(int value)
    {
        binary_search_tree*last_parent_I_am_his_left=this;
        binary_search_tree*searched_for_value=this;
        while(searched_for_value->data!=value)
        {
            if(searched_for_value->data<value)
                searched_for_value=searched_for_value->right;
            else
                last_parent_I_am_his_left=searched_for_value,searched_for_value=searched_for_value->left;
        }
        return make_pair(last_parent_I_am_his_left,searched_for_value);
    }
    int find_successor(int value)
    {
       if(this->binary_search_tree::max()==value|| !iterative_search(value))
           return -1;
       pair<binary_search_tree*,binary_search_tree*>pp=find(value);//it's first is the parent...second equal to the node;
       if(pp.second->right)
       {
           return pp.second->right->min_value();
       }
       return pp.first->data;
    }
    int nearest_common_parent(int child1,int child2)
    {
        if(!iterative_search(child1)||!iterative_search(child2))
            return -1234;
        binary_search_tree*curr=this;
        binary_search_tree*prev=nullptr;
        if(this->data==child1||this->data==child2)
            return -1234;
        while(curr)
        {
            if(curr->data==child1||curr->data==child2)
                return prev->data;
            prev=curr;
            if(child1>curr->data&&child2<curr->data||child2>curr->data&&child1<curr->data)
                return curr->data;
            else if(child1>curr->data)
                curr=curr->right;
            else
                curr=curr->left;
        }
        return -1234;
    }
    binary_search_tree(int data,binary_search_tree*left,binary_search_tree*right)
    {
        this->data=data;
        this->left=left;
        this->right=right;
    }
    binary_search_tree()
    {
        length=0;
        right=left=nullptr;
        data=-1;
    }
    binary_search_tree* build_binary_search_tree(vector<int>&values,int start=0,int end=-10)
    {
        if(end==-10)
        {
            end=(int)values.size()-1;
            sort(values.begin(),values.end());
        }
        if(start>end)
            return nullptr;
        int mid=start+(end-start)/2;
        binary_search_tree*branch_left=build_binary_search_tree(values,start,mid-1);
        binary_search_tree*branch_right= build_binary_search_tree(values,mid+1,end);
        binary_search_tree*root=new binary_search_tree(values[mid],branch_left,branch_right);
        return root;
    }
    binary_search_tree(vector<int>&values)
    {
        binary_search_tree*temp=build_binary_search_tree(values);
        this->data=temp->data;
        this->left=temp->left;
        this->right=temp->right;
    }
    binary_search_tree(int data){
        this->data=data;
        left=right=nullptr;
        length++;
    }
    void insert_recursive(int value)
    {
        if(value>data)
        {
            if(right)
                right->insert_recursive(value);
            else
                right=new binary_search_tree{value};
        }
        else if(value<data)
        {
            if(left)
                left->insert_recursive(value);
            else
                left=new binary_search_tree{value};
        }
    }
    void insert_iterative(int value)
    {
        if(length==0)
        {
            this->data=value;
            length++;
            return;
        }
        binary_search_tree*curr=this;
        while(true)
        {
            if(curr->data==value)
                return;
            if(!curr->left&&value<=curr->data)
            {
                curr->left=new binary_search_tree{value};
                length++;
                break;
            }
            if(!curr->right&&value>curr->data)
            {
                curr->right=new binary_search_tree{value};
                length++;
                break;
            }
            if(value>curr->data)
                curr=curr->right;
            else
                curr=curr->left;
        }

    }
    void inorder_traversal()
    {
        if(left)
            left->inorder_traversal();
        cout<<this->data<<" ";
        if(right)
            right->inorder_traversal();
    }
    void level_order_traversal()
    {
        queue<binary_search_tree*>q;
        q.push(this);
        while(!q.empty())
        {
            int sz=(int)q.size();
            while(sz--)
            {
                binary_search_tree*curr=q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                cout<<curr->data<<" ";
            }
        }
    }
    bool iterative_search(int value)
    {
        binary_search_tree* temp=this;
        while(temp)
        {
            if(temp->data==value)
                return true;
            if(temp->data>value) {
                if (temp->left)
                    temp = temp->left;
                else
                    break;
            }
            else {
                if (temp->right)
                    temp = temp->right;
                else
                    break;
            }
        }
        return false;
    }
    bool recursive_search(int value)
    {
        if(value==this->data)
            return true;
        if(data<value)
            return right&&right->recursive_search(value);
        else
            return left&&left->recursive_search(value);

    }
    bool is_BST()
    {
        vector<int>v;
        complete(v);
        if(sorted(v))
            return true;
        return false;
    }
    bool rec_is_BST(int mn=INT_MIN,int mx=INT_MAX)
    {
        bool cur=this->data>mn&&this->data<mx;
        if(!cur)
            return false;
        if(left)
        {
            return left->rec_is_BST(mn,this->data);
        }
        if(right)
        {
            return right->rec_is_BST(this->data,mx);
        }
        return cur;
    }
    int smallest_kth(int &k)
    {
        if(k==0)
            return -1;
        if(left)
        {
           int res= left->smallest_kth(k);
            if(k==0)
                return res;
        }
        --k;
        if(k==0)
            return this->data;
        if(right)
        {
            int res=right->smallest_kth(k);
            if(k==0)
                return res;
        }
        return -1;
    }
    int min_value()
    {
        binary_search_tree*temp=this;
        while(temp&&temp->left)
            temp=temp->left;
        return temp->data;
    }
    bool is_degenrate(vector<int>&preorder)
    {
        int n=(int)preorder.size();
        bool max_than_me=false;
        bool min_than_me=false;
        for(int i=0;i<n;i++)
        {
            max_than_me= false;
            min_than_me=false;
            for(int j=i+1;j<n;j++)
            {
                if(preorder[j]>preorder[i])
                    max_than_me=true;
                if(preorder[j]<preorder[i])
                    min_than_me=true;
            }
            if(max_than_me&&min_than_me)
                return false;
        }
        return true;
    }
    bool recursive_is_degnerate()
    {
        bool res=left&&right;
        if(left&&!res)
            left->recursive_is_degnerate();
        if(right&&!res)
            right->recursive_is_degnerate();
        return !res;
    }
    int lca(int x,int y)
    {
        if(x>this->data&&y>this->data)
            return right->lca(x,y);
        else if(x<this->data&&y<this->data)
            return left->lca(x,y);
        return this->data;
    }
    int size()
    {
        return length;
    }
};
int main() {
    khaled
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(auto &val:a)
        cin>>val;
    sort(a.begin(),a.end());
    int res=1;
    for(auto &val:a)
    {
        if(k%val==0)
        {
            res=val;
        }
    }
    cout<<k/res;
}