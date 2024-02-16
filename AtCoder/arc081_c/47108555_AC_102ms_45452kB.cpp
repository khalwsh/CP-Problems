#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int long long
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
bool valid(long long i,long long j,long long n,long long m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &m=INT64_MAX){if (power == 1 || power == 0)return base * power + (!power);long long res = (fast_power(base, power / 2, m) % m) % m;if (power & 1)return mul(base,mul(res,res,m),m);else return mul(res,res,m);}
int log2_floor(long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : 0;}
int power_of_2(int n){ return __builtin_popcountll(n)==1;}
bool line_checking(int a1,int a2,int a3,int b1,int b2,int b3) {return (a3 - a1) * (b2 - b1) == (a2 - a1) * (b3 - b1);}
const int N=2e5+1;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=2e17+1;
int dx[]{1,-1,0,0,1,1,-1,-1};
int dy[]{0,0,1,-1,1,-1,1,-1};
const long double pi=3.14159265350979323846,eps=1e-9;
/*==============================================  KHALWSH  ==============================================*/
string s;
int nxt[N][26];
int front[26];
bool cmp(string &a,string&b){
    if(a.size()!=b.size())return a.size()<b.size();
    return a<b;
}
bool vis[N];
void bfs(){
    queue<pair<string,int>>q;
    for(char i='a';i<='z';i++) {
        string jj;
        jj+=i;
        q.push(make_pair(jj, front[i - 'a']));
    }
    while(!q.empty()){
        int siz=(int)q.size();
        vector<string>res;
        while(siz--) {
            int cur = q.front().second;
            string val = q.front().first;
            q.pop();
            for (char i = 'a'; i <= 'z'; i++) {
                if (nxt[cur][i - 'a'] == -1) {
                    cout<<val+i<<line;
                    exit(0);
                }
                if(!vis[nxt[cur][i-'a']])
                    q.push({val + i, nxt[cur][i - 'a']});
                vis[nxt[cur][i-'a']]=true;
            }
        }
    }
}
signed main() {
    khaled
    memset(front,-1,sizeof front);
    cin>>s;
    memset(nxt,-1,sizeof nxt);
    for(int i=(int)s.size()-1;i>=0;i--){
        for(char j='a';j<='z';j++){
            nxt[i][j-'a']=front[j-'a'];
        }
        front[s[i]-'a']=i;
    }
    for(int i=0;i<26;i++){
        if(front[i]==-1){
            cout<<(char)(i+'a')<<line;
            exit(0);
        }
    }
    bfs();
}