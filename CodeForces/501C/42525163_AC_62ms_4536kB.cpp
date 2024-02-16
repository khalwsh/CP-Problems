#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
class AVL_TREE{
private:
    int data{};
    int height{};
    AVL_TREE*left{},*right{};
    int balance_factor()
    {
        return child_height(left)- child_height(right);
    }
    int child_height(AVL_TREE*node)
    {
        if(!node)
            return -1;
        return node->height;
    }
    AVL_TREE*left_rotation(AVL_TREE*node)
    {
        AVL_TREE*temp=node->right->left;
        node->right->left=node;
        AVL_TREE*ret=node->right;
        node->right=temp;
        update_height();
        return ret;
    }
    void update_height()
    {
        height=1+max(left->height,right->height);
    }
public:
    AVL_TREE&operator=(const AVL_TREE&equal)=delete;
    AVL_TREE(const AVL_TREE&copy)=delete;

};
int main() {
    khaled
    int n;
    cin>>n;
    vector<int>d(n),xor_sum(n);
    for(int i=0;i<n;i++)
        cin>>d[i]>>xor_sum[i];
    queue<pair<int,int>>q;
    vector<bool>vis(n);
    vector<pair<int,int>>res;
    for(int i=0;i<n;i++)
    {
        if(d[i]==1)
            q.push(make_pair(i,xor_sum[i])),vis[i]=true;
    }
    while(!q.empty())
    {
        res.emplace_back(q.front());
        pair<int,int>p=q.front();
        q.pop();
        d[p.second]--;
        xor_sum[p.second]^=p.first;
        if(d[p.second]==1&&!vis[p.second])
            q.push(make_pair(p.second,xor_sum[p.second])),vis[p.second]=true;
    }
    for(auto &val:res)
        if(val.first>val.second)
            swap(val.first,val.second);
    set<pair<int,int>>pp;
    for(auto &val:res)
        pp.insert(val);
    cout<<pp.size()<<line;
    for(auto &val:pp)
        cout<<val.first<<" "<<val.second<<line;
}