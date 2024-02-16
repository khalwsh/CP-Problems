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
long long res=0;
void dfs(long long node,int parent,vector<pair<int,int>>adj[],int &my_max,int counter)
{
    my_max=max(my_max,counter);
    for( auto &val:adj[node])
    {
        if(val.second==parent)
            continue;
        dfs(val.second,node,adj,my_max,counter+val.first);
    }
}
signed main() {
    khaled
    int t;
    t=1;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int>>adj[n];//road length edge
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            int cost;
            cin>>cost;
            adj[x].emplace_back(cost,y);
            adj[y].emplace_back(cost,x);
            res+=cost*2;
        }
        long long temp=0;
        dfs(0,-1,adj,temp,0);
        //cout<<temp<<line;

        cout<<res-temp;
        cout<<line;
    }
}