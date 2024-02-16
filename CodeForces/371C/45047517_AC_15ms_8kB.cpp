#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//#include <ext/pb_ds/detail/standard_policies.hpp>//this file only make me able to use ordered set
using namespace __gnu_pbds;
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool line_checking(long long a1,long long b1,long long a2,long long b2,long long a3,long long b3){return (a3-a1)*(b2-b1)==(a2-a1)*(b3-b1);}
bool valid(int i,int j,int n,int m){return i>=0&&i<n&&j>=0&&j<m;}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &mod=INT64_MAX){if(power==0)return 1ll;long long d= fast_power(base,power/2)%mod;d=mul(d,d,mod);if(power&1)return mul(d,base,mod);else return d;}
long long mod_inverse_fermat(long long B,const long long&mod=1e9+7){ return fast_power(B,mod-2,mod);}//mod is prime
vector<int>mod_inverse_for_range(int p){vector<int>inv(p,1);for(int i=2;i<p;i++) {inv[i] = ( p - (p / i) * inv[p % i] % p ) % p;}return inv;}//mod is prime
vector<long long>factorial(long long n,const long long& mod){vector<long long>v(n+1,1);for(int i=2;i<=n;i++)v[i]=mul(i,v[i-1],mod);return v;}
int dx[]{1,-1,0,0,1,1,-1,-1};//0->4 normal,4->8 diagonal
int dy[]{0,0,1,-1,1,-1,1,-1};
const long double pi=3.14159265350979323846;
const long double Eps=1e-10;
#define int __int128
template<class integer>
inline integer to_int(const string& s, size_t* idx = 0, int base = 10) {
    size_t n = s.size(), i = idx ? *idx : 0; bool sign = false; integer x = 0;
    if (s[i] == '-')
        ++i, sign = true;
    function<int(char)> char_to_digit = [&](char c) {
        static const int d[] = {'a'-10,'0'};
        return tolower(c)-d[isdigit(c)]; };
    while (i < n)
        x *= base, x += char_to_digit(s[i++]);
    if (idx)
        *idx = i;
    return sign ? -x : x; }

template<class integer>
inline string to_string(integer x, int base = 10) {
    bool sign = false; string s;
    if (x < 0)
        x = -x, sign = true;
    function<char(int)> digit_to_char = [](int d) {
        static const char c[] = {'a'-10,'0'};
        return c[d < 10]+d; };
    do
        s += digit_to_char(x%base), x /= base;
    while (x > 0);
    if (sign)
        s += '-';
    reverse(s.begin(),s.end());
    return s; }

template<class integer>
inline istream& read(istream& is, integer& x) {
    string s; is >> s, x = to_int<integer>(s); return is; }

template<class integer>
inline ostream& write(ostream& os, integer x) { return os << to_string(x); }

using  lll =   signed __int128;
using ulll = unsigned __int128;

inline istream& operator>>(istream& is,  lll &x) { return  read(is,x); }
inline istream& operator>>(istream& is, ulll &x) { return  read(is,x); }
inline ostream& operator<<(ostream& os,  lll  x) { return write(os,x); }
inline ostream& operator<<(ostream& os, ulll  x) { return write(os,x); }
//instead of less if write less_equal it will be considered as multiset,same as greater_equal
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// find_by_order-->get the index value, order_of_key-->how many smaller than key and with in set
const int N=5e6+2;
const int mod=1e9+7;
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/

int bread_need=0,sgoa_need=0,cheese_need=0;
bool can(int target,int bread,int sgoa,int cheese,int cost_bread,int cost_sgoa,int cost_cheese,int money){
   int need_b=target*bread_need;
   int need_s=target*sgoa_need;
   int need_c=target*cheese_need;
   if(bread<need_b)money-=(need_b-bread)*cost_bread;
   if(cheese<need_c)money-=(need_c-cheese)*cost_cheese;
   if(sgoa<need_s)money-=(need_s-sgoa)*cost_sgoa;
   return money>=0;
}
signed main() {
    khaled
    string ss;
    cin>>ss;
    for(auto &val:ss){
        if(val=='B')bread_need++;
        else if(val=='S')sgoa_need++;
        else cheese_need++;
    }
    int b,s,c;
    cin>>b>>s>>c;
    int cb,cs,cc;
    cin>>cb>>cs>>cc;
    int r;
    cin>>r;
    int left=0,right=1e16;
    int res=0;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(can(mid,b,s,c,cb,cs,cc,r))
            res=mid,left=mid+1;
        else
            right=mid-1;
    }
    cout<<res<<line;
}