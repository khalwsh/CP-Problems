#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
class trie{
private:
    bool leaf{};
    static const int size=26;
    trie*child[size];
public:
    trie()
    {
        memset(child,0,sizeof(child));
    }
    void insert(string s,int index=0)
    {
        if(s.size()==index)
        {
            leaf=true;
            return;
        }
        else
        {
            if(child[s[index]-'a']==nullptr)
                child[s[index]-'a']=new trie();
            child[s[index]-'a']->insert(s,index+1);
        }
    }
    bool search_word(string s,int index=0)
    {
        if(s.size()==index)
            return leaf;
        else
        {
            if(child[s[index]-'a']==nullptr)
                return false;
            return child[s[index]-'a']->search_word(s,index+1);
        }
    }
    bool search_prefix(string s,int index=0)
    {
        if(s.size()==index)
            return true;
        else
        {
            if(child[s[index]-'a']==nullptr)
                return false;
            return child[s[index]-'a']->search_prefix(s,index+1);
        }
    }
    bool iterative_search_word(string s)
    {
        trie *temp=this;
        for(auto &val:s)
        {
            if(temp->child[val-'a']==nullptr)
                return false;
            temp=temp->child[val-'a'];
        }
        return temp->leaf;
    }
    void iterative_insert(string s)
    {
        trie*temp=this;
        for(auto &val:s)
        {
            if(temp->child[val-'a']==nullptr)
                temp->child[val-'a']=new trie();
            temp=temp->child[val-'a'];
        }
        temp->leaf=true;
    }
    string first_word_prefix(const string&str)
    {
        trie*temp=this;
        for(int i=0;i<str.size();i++)
        {
            int ch=str[i]-'a';
            if(!temp->child[ch]) {
                break;
            }
            if(temp->child[ch]->leaf)
                return str.substr(0,i+1);
            temp=temp->child[ch];
        }
        return str;
    }
    void insert_path(vector<string>&paths)
    {
        trie*temp=this;
        for(auto &val:paths)
        {
            for(auto &i:val)
            {
                int cur=i-'a';
                if(temp->child[cur]==nullptr)
                    temp->child[cur]=new trie();
                temp=temp->child[cur];
            }
        }
        temp->leaf=true;
    }
    bool path_exist(vector<string>&path)
    {
        trie*temp=this;
        for(auto &val:path)
        {
            for(auto &i:val)
            {
                int cur=i-'a';
                if(temp->child[cur]==nullptr)
                    return false;
                temp=temp->child[cur];
            }
        }
        return true;
    }
};
vector<int>paths;
vector<int>res;
bool done=false;
void generate_path_between_two_nodes(int node_start,int node_target,vector<int>adj[],int parent)
{
    if(node_start==node_target)
    {
        done=true;
        paths.emplace_back(node_start);
        return;
    }
    if(!done) {
        paths.emplace_back(node_start);
        for (auto &val: adj[node_start]) {
            if (parent == val)
                continue;
            generate_path_between_two_nodes(val, node_target, adj, node_start);
        }
        if(!done)
        paths.pop_back();
    }

}
int main() {
    khaled
    int n;
    cin>>n;
    vector<int>adj[n];
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    vector<int>leafs;
    int count_leafs=0;
    for(int i=1;i<n;i++)
    {
        if(adj[i].size()==1)
            count_leafs++;
    }
    while(count_leafs--)
    {
        int x;
        cin>>x;
        leafs.emplace_back(x-1);
    }
    generate_path_between_two_nodes(0,leafs[0],adj,-1);
    for(int i=1;i<leafs.size();i++)
      done=false,paths.pop_back(),  generate_path_between_two_nodes(leafs[i-1],leafs[i],adj,-1);
    done=false,paths.pop_back(), generate_path_between_two_nodes(leafs[leafs.size()-1],0,adj,-1);
    if(paths.size()>2*n-1)
        cout<<-1;
    else {
        for (auto &val: paths)
            cout << val + 1 << " ";
    }
}