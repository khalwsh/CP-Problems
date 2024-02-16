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
#define int long long
void dfs(int node,int parent,vector<pair<int,int>>adj[],vector<int>&colors,int dist,bool color)
{
    colors[node]=color;
    for(auto &val:adj[node])
    {
        if(val.first==parent)
            continue;
        if(val.second&1)
            dfs(val.first,node,adj,colors,dist+val.second,!color);
        else
            dfs(val.first,node,adj,colors,dist+val.second,color);
    }
}
signed main() {
    khaled
    int n;
    cin>>n;
    vector<pair<int,int>>adj[n];
    for(int i=1;i<n;i++)
    {
        int x,y,cost;
        cin>>x>>y>>cost;
        adj[x-1].emplace_back(y-1,cost);
        adj[y-1].emplace_back(x-1,cost);
    }
    vector<int>colors(n,-1);
        dfs(0, -1, adj, colors, 0, false);
    for(auto &val:colors)
        cout<<val<<line;

}