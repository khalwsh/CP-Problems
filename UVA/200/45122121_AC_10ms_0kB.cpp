#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 2e5+5;
vector<int> graph[N];
bool used[26];
bool vis[N];
stack<int> topSort;

void dfs(int node){
    vis[node] = 1;
    for(int child:graph[node]){
        if(!vis[child]) dfs(child);
    }
    topSort.push(node);
}

int main(){

    fastInputOutput();
    string s, p;
    cin>>s;
    while(cin>>p){
        if(p == "#") break;
        int sz1 = s.size(), sz2 = p.size();
        for(int i=0;i<min(sz1, sz2);i++){
            if(s[i] != p[i]){
                graph[s[i]-'A'].push_back(p[i]-'A');
                used[s[i]-'A'] = 1;
                used[p[i]-'A'] = 1;
                break;
            }
        }
        s = p;
    }
    for(int i=0;i<26;i++){
        if(!vis[i] && used[i]){
            dfs(i);
        }
    }
    while(topSort.size()){
        cout<<char(topSort.top()+'A');
        topSort.pop();
    }
    cout<<endl;
    return 0;

}