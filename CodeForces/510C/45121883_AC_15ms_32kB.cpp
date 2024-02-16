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
bool cycle(int node,vector<int>&vis,vector<int>adj[])
{
    vis[node]=1;
    bool res=false;
    for(auto &val:adj[node])
    {
        if(vis[val]==0)
            res=cycle(val,vis,adj);
        else if(vis[val]==1)
            res=true;
    }
    vis[node]=2;
    return res;

}
stack<int>after_sort;
void topo_sort(int node,vector<int>adj[],vector<int>&vis)
{
    vis[node]=true;
    for(auto &val:adj[node]) {
        if (vis[val])continue;
        topo_sort(val, adj, vis);
    }
    after_sort.push(node);
}
int main() {
    khaled
    int n;
    cin>>n;
    vector<string>v(n);
    for(auto &val:v)
        cin>>val;
    vector<int>adj[26];
    bool flag=false;
    for(int i=0;i+1<n;i++)
    {
        for(int j=0;j<min(v[i].size(),v[i+1].size());j++)
        {
            if(v[i][j]!=v[i+1][j]) {
                adj[v[i][j] - 'a'].emplace_back(v[i + 1][j] - 'a');
                break;
            }
            if(j==min(v[i].size(),v[i+1].size())-1)
            {
                if(v[i+1].size()<v[i].size())
                {
                    cout<<"Impossible";
                    return 0;
                }
            }
        }
    }
   /* for(auto &val:adj)
    {
        for(auto &i:val)
            cout<<i<<" ";
        cout<<line;
    }*/
    for(int i=0;i<26;i++)
    {
       if((int)adj[i].size())
       {
           vector<int>vis(26,0);
           if(cycle(i,vis,adj))
           {
               cout<<"Impossible";
               return 0;
           }
       }
    }
    vector<int>vis(26,0);
    for(auto &val:vis)
        val=0;
    for(int i=0;i<26;i++)
    {
        if(!vis[i])
            topo_sort(i,adj,vis);
    }
    while(!after_sort.empty())
    {
        cout<<(char)(after_sort.top()+'a');
        after_sort.pop();
    }
    cout<<line;

}