#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF 0x7FFFFFFF
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int,int>
#define mem(name, value) memset(name, value, sizeof(name))

typedef long long ll;
typedef unsigned long long ull;

int dp[10001];
int coin[100];

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k,t;

    scanf("%d",&t);

    for(int c=1;c<=t;c++)
    {
        pf("Case %d: ",c);

        scanf("%d%d",&n,&k);

        for(int i=0;i<n;i++)
            scanf("%d",&coin[i]);

        mem(dp,0);

        dp[0] = 1; /// By taking No money at all

        for(int i=0;i<n;i++)
            for(int j=coin[i],r=0;j<=k;j++,r++) /// r = Change Money :)
                dp[j]+=dp[r],dp[j]%=MOD;

        pif(dp[k]);
    }
    return 0;
}