
/*
                         -------------Shuvo's code-----_______
                        /''''''''''(______O] ----------____  \______/]_
     __...---'"""\_ --''        Metropolitan university     ___________@ -> ->  -> - --  - -- - ---- ->>
 |'''                   ._   _______________=---------"""""""
 |                ..--''|   l L |_l   |
 |          ..--''      .  /-___j '   '
 |    ..--''           /  ,       '   '
 |--''                /           `    \
                      L__'         \    -
                                    -    '-.
                                     '.    /
                                       '-./
*/

///   ------------ Bismillah hirrahman nirrahim ----------   ///

#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long
#define sc(n) scanf("%I64d", &n);
#define pr(n) printf("%I64d\n", n);
#define prr(n, m) printf("%I64d %I64d\n", n, m);
#define prrr(n, m, p) printf("%I64d %I64d %I64d\n", n, m, p);
#define lp(i,s,n) for(long long  i = s; i<n; i++)
#define pl(n) for(long long i=n-1; i>=0; i--)
#define  ars(arr,s,e) sort(arr+s,arr+n);
#define pb push_back
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0)

long long int mx = 1e18;
long long int mn = -1e18;
using namespace std;

ll b[110];

ll dp[110][110];

struct my
{
    ll x;
    ll y;
} a[110];

bool cmp(my aa, my bb)
{
    return aa.y<bb.y;
}

ll wow(ll pos, ll en, ll k, ll w)
{

    if(k<=0) return 0;
    if(pos>=en) return 0;

    ll &ret = dp[pos][k];
    if(ret != -1) return ret;

    ll cnt = 0, i;
    for(i = pos; i<en & a[pos].y+w >= a[i].y; i++)
    {
        cnt++;
    }

    ll val1 = cnt+wow(i, en, k-1, w);
    ll val2 = wow(pos+1, en, k, w);

    return ret = max(val1, val2);
}

int main()
{
    FastRead;
    ll p,q,r,s,t,i, j,ii, x,len,  jj, n, w, k, tc = 0, y;
    string str, str2;
    cin >> t;
    while(t--)
    {
        cin >> n >> w >> k;

        for(i=0; i<n; i++)
        {
            cin >> x >> y;
            a[i].x = x;
            a[i].y = y;
        }

        sort(&a[0], &a[n], cmp);

        memset(dp, -1, sizeof dp);
        ll ans = wow(0, n, k, w);

        cout << "Case "<< ++tc << ": " << ans << endl;
    }
    return 0;
}