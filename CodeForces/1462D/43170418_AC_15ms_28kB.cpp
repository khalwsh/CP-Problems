#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        long long sum = 0;
        for (auto  &x : a) {
            cin >> x;
            sum += x;
        }
        bool work=true;
        for(int i=n;i>=1;i--)
        {
            if(sum%i==0)
            {
                long long target=sum/i;
                long long cur=0;
                work=true;
                for(auto &val:a)
                {
                    cur+=val;
                    if(cur>target) {
                        work = false;
                        break;
                    }
                    cur%=target;
                }
                if(work) {
                    cout << n - i;
                    break;
                }
            }
        }
        cout<<line;
    }
}