#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<vector<long long>>dp_nCr(100,vector<long long>(100,-1));
long long nCr(long long n,long long r){if(r == 0 || r == n)return 1;if(r == 1 || r == n - 1)return n;if(dp_nCr[n][r]!=-1)return dp_nCr[n][r]; return dp_nCr[n][r]= nCr(n - 1, r) + nCr(n - 1, r - 1);}
long long derangement(int n){if(n == 0)return 1;if(n == 1)return 0;if(n == 2)return 1;return (n - 1)*(derangement(n - 1) + derangement(n - 2));}
bool line_checking(long long a1,long long b1,long long a2,long long b2,long long a3,long long b3){return (a3-a1)*(b2-b1)==(a2-a1)*(b3-b1);}
bool valid(long long i,long long j,long long n,long long m){return i>=0&&i<n&&j>=0&&j<m;}
long long safe_mul_mod(long long a,long long b,const long long &mod){long long res=0,y=a%mod;while(b>0){if(b&1){res=((res%mod)+(y%mod))%mod;}y=((y%mod)*(2ll%mod))%mod;b>>=1;}return (res%mod);}
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}
long long fast_power(long long base,long long power,const long long &m=INT64_MAX){if (power == 1 || power == 0)return base * power + (!power);long long res = (fast_power(base, power / 2, m) % m) % m;if (power & 1)return mul(base,mul(res,res,m),m);else return mul(res,res,m);}
long long mod_inverse_fermat(long long B,const long long&mod=1e9+7){ return fast_power(B,mod-2,mod);}//mod is prime
vector<int>mod_inverse_for_range(int p){vector<int>inv(p,1);for(int i=2;i<p;i++) {inv[i] = ( p - (p / i) * inv[p % i] % p ) % p;}return inv;}//mod is prime
vector<long long>factorial(long long n,const long long& mod){vector<long long>v(n+1,1);for(int i=2;i<=n;i++)v[i]=mul(i,v[i-1],mod);return v;}
long long NCR_MOD(long long n, long long r,vector<long long>&fact,const long long&mod){return mul(mul(fact[n], mod_inverse_fermat(fact[n - r], mod), mod), mod_inverse_fermat(fact[r], mod), mod);}
long long phi(long long n) {long long result = n;for (int i = 2; i * i <= n; i++) {if (n % i == 0) {while (n % i == 0)n /= i;result -= result / i;}}if (n > 1)result -= result / n;return result;}
int dx[]{1,-1,0,0,1,1,-1,-1};//0->4 normal,4->8 diagonal
int dy[]{0,0,1,-1,1,-1,1,-1};
const long double pi=3.14159265350979323846;
const long double Eps=1e-10;
#define int long long
template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N=1e6+1;
const int mod=1e9+7;
const long long inf=3e18;
//remember ya 3l2 enter this gym on your free time :The 2022 SDUT Summer Trials
//    fast_power(base,power,m) == fast_power(base,power%phi(m),m); if gcd(base,m)==1;
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/
bool wheel(int index,int degree,int n,vector<int>&v){
    if(index==n){
        return degree%360==0;
    }
    return wheel(index+1,degree+v[index],n,v)||wheel(index+1,degree-v[index],n,v);
}
int factorial(int i){
    if(i==0)return 1;
    return i* factorial(i-1);
}
int lis(int index,vector<int>&v,int last_taken){
    if(index==v.size()){
        return 0;
    }
    if(v[index]>last_taken){
        return max(lis(index+1,v,v[index])+1,lis(index+1,v,last_taken));
    }else
        return lis(index+1,v,last_taken);
}
int count_twos(int n){
    bitset<63>b(n);
    return (int)b.count();
}
bool palndor(string&s){
    int left=0,right=(int)s.size()-1;
    while(left<right){
        if(s[left]==s[right]);
        else
            return false;
        left++,right--;
    }
    return true;
}
void problem_s(){
    int n;
    vector<int>v;
    cin>>n;
    v.resize(n);
    for(auto &val:v)cin>>val;
    cout<<(wheel(0,0,n,v)?"YES":"NO")<<line;
}
void problem_e(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &val:v)cin>>val;
    cout<<lis(0,v,-inf);
}
void problem_f(){
    int t;
    cin>>t;
    while(t--){
        int n,z;
        cin>>n>>z;
        int res=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            res=max(z|x,res);
        }
        cout<<res<<line;
    }
}
void problem_g(){
    while(true){
        int t,n;
        cin>>t>>n;
        if(!n&&!t)break;
        vector<int>v(n);
        for(auto &val:v)cin>>val;
        sort(v.rbegin(),v.rend());
        cout<<"Sums of "<<t<<":"<<line;
        vector<vector<int>>res;
        bool found=false;
        for(int i=1;i<(1ll<<n);i++){
            bitset<32>b(i);
            vector<int>sums;
            int sum=0;
            for(int j=0;j<32;j++){
                if(b[j]){
                    sum+=v[j];
                    sums.emplace_back(v[j]);
                }
            }
            if(sums.empty()||sum!=t)continue;
            res.emplace_back(sums);
            found=true;
        }
        if(!found){
            cout<<"NONE"<<line;
        }else{
            set<vector<int>>s;
            for(auto &val:res)s.insert(val);
            res.clear();
            for(auto &val:s)res.emplace_back(val);
            sort(res.rbegin(),res.rend());
            for(auto &val:res){
                for(int j=0;j<val.size();j++){
                    cout<<val[j];
                    if(j==val.size()-1)break;
                    cout<<"+";
                }
                cout<<line;
            }
        }
    }
}
void problem_h(){
    int t;
    cin>>t;
    vector<int>v;
    for(int i=1;i<=15;i++)v.emplace_back(factorial(i));
    while(t--){
        int n;
        cin>>n;
        int res= count_twos(n);
        for(int i=1;i<(1<<15);i++){
            bitset<40>b(i);
            int sum=0;
            int step=0;
            for(int j=0;j<40;j++){
                if(b[j]&&j<v.size()){
                    sum+=v[j];
                    step++;
                }
            }
            if(n-sum<0)continue;
            res=min(res,step+ count_twos(n-sum));
        }
        cout<<res<<line;
    }
}
void problem_i(){
    int n,l,r,x;
    cin>>n>>l>>r>>x;
    vector<int>v(n);
    for(auto &val:v)cin>>val;
    int number_of_ways=0;
    for(int i=1;i<(1ll<<n);i++){
        bitset<16>b(i);
        int mn=INT_MAX;
        int mx=INT_MIN;
        int tot=0;
        if(b.count()==1)continue;
        for(int j=0;j<16;j++){
            if(b[j]){
                mn=min(mn,v[j]);
                tot+=v[j];
                mx=max(mx,v[j]);
            }
        }
        if(tot>=l&&tot<=r&&mx-mn>=x){
            number_of_ways++;
        }
    }
    cout<<number_of_ways<<line;
}
void problem_j(){
    int t;
    cin>>t;
    while(t--){
        int mx;
        int n;
        cin>>mx>>n;
        vector<int>v(n);
        bool found=false;
        for(auto &val:v)cin>>val;
        for(int i=1;i<(1ll<<n);i++){
            bitset<32>b(i);
            int sum=0;
            for(int j=0;j<32;j++){
                if(b[j]){
                    sum+=v[j];
                }
            }
            if(sum==mx){
                found=true;
                break;
            }
        }
        found=found||(mx==0);
        cout<<(found?"YES":"NO")<<line;
    }
}
void problem_m(){
    int t;
//    cin>>t
    t=1;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(auto &val:v)cin>>val;
        int res=0;
        for(int i=0;i<(1ll<<n);i++){
            bitset<21>b(i);
            int sum=0;
            for(int j=0;j<21;j++){
                if(b[j]){
                    sum|=v[j];
                }
            }
            res+=sum;
        }
        cout<<res<<line;
    }
}
void problem_o(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<(min(a,b)^max(a,b))<<line;
    }
}
void problem_p(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<1<<" "<<(1^n)<<line;
    }
}
void problem_q(){
    string s;
    cin>>s;
    string res;
    for(int i=1;i<(1<<s.size());i++){
        bitset<11>b(i);
        string temp;
        for(int j=0;j<11;j++){
            if(b[j])
                temp+=s[j];
        }
        if(palndor(temp))res=max(res,temp);
    }
    cout<<res<<line;
}
signed main() {
    khaled
   // problem_e();
 //problem_f();
//    problem_g();
   // problem_h();
 //problem_i();
   //problem_j();
    problem_m();
//    problem_o();
//    problem_p();
//    problem_q();
//    problem_s();
}