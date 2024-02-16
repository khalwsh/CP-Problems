#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int long long
#define double long double
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
bool valid(long long i,long long j,long long n,long long m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &m=INT64_MAX){if (power == 1 || power == 0)return base * power + (!power);long long res = (fast_power(base, power / 2, m) % m) % m;if (power & 1)return mul(base,mul(res,res,m),m);else return mul(res,res,m);}
int log2_floor(long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : 0;}
int power_of_2(int n){ return __builtin_popcountll(n)==1;}
bool line_checking(int a1,int b1,int a2,int b2,int a3,int b3) { return (b2-b1)*(a2-a3)==(b2-b3)*(a2-a1); }
pair<int,int> rotate(int i,int j,int n){ return make_pair(j,n-1-i); }
const int N=2e5+5;
const int mod=1e9+7;
//const int mod = 998244353;
const long long inf=3e18+1;
int dx[]{1,-1,0,0,1,1,-1,-1};
int dy[]{0,0,1,-1,1,-1,1,-1};
const double pi=3.14159265350979323846,eps=1e-8;
/*==============================================  KHALWSH  ==============================================*/
struct Bit{
    int N=1<<18;
    vector<int>tree;
    void init(){
        tree.resize(this->N);
    }
    void add(int pos,int value){
        for(int i=pos+1;i<=N;i+=i&-i)tree[i-1]+=value;
    }
    int get(int pos) {
        int sum = 0;
        for (int i = pos + 1; i; i -= i & -i)sum += tree[i - 1];
        return sum;
    }
    int find(int t){
        int st=0;
        for(int sz=N>>1;sz;sz>>=1){
            if(tree[st+sz-1]<t){
                t-=tree[(st+=sz)-1];
            }
        }
        return st;
    }
};
struct MultiSet{
    Bit bit;
    MultiSet(){
        bit.init();
        bit.add(0,-1);
    }
    void insert(int value){
        bit.add(value,1);
    }
    void erase(int value){
        bit.add(value,-1);
    }
    int count(int value){
        return bit.get(value)-bit.get(value-1);
    }
    int size(){
        return bit.get(bit.N-1)+1;
    }
    int at(int index){
        return bit.find(index);//return the value which at index (index)
    }
    int order_of_key(int key){
        int left = 0 , right = size()-1;
        int res = 0;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(at(mid)>=key){
                res = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return res;
    }
};
signed main() {
    khaled
    int n;cin >> n;
    string s;cin >> s;
    string target = s;
    reverse(target.begin(),target.end());
    deque<int>adj[26];
    for (int i = 0; i < s.size(); ++i) {
        adj[s[i] - 'a'].push_back(i);
    }
    MultiSet st;
    for(int i = 0;i < s.size();++i){
        st.insert(i);
    }
    int ans = 0;
    for (int i = 0; i < target.size(); ++i) {
        int ind = adj[target[i] - 'a'].front();
        ans += (int)st.order_of_key(ind);
        st.erase(ind);
        adj[target[i] - 'a'].pop_front();
    }
    cout << ans;
}