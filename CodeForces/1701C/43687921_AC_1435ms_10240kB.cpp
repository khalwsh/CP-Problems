#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool can(long long value,vector<int>&tasks,int n,int m,map<int,int>&mp)
{
    long long help = 0, need = 0;
    for(int i=1;i<=n;i++){
        if (value >= mp[i])
            help += (value - mp[i]) / 2;//the help i need to offer
        else
            need += mp[i] - value;//i have how many free hours to help other workers
    }
    return need <= help;//if i need to offer help than i can affort it is wrong ans else it is right
}
int main() {
    khaled
    int t;
    cin>>t;
    while(t--) {
        int n;
        int m;
        cin >> n >> m;
        vector<int> tasks(m);
        for (auto &val: tasks)
            cin >> val;
        map<int,int>mp;
        for(auto &val:tasks)
            mp[val]++;
        long long left=1,right=1e14;
        long long res=-1;
        while(left<=right)
        {
            long long mid=left+(right-left)/2;
            if(can(mid,tasks,n,m,mp))
              res=mid,right=mid-1;
            else
                left=mid+1;
        }
        cout<<res<<line;
    }

}