#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//#define int long long
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace __gnu_pbds;
using namespace std;
/*==============================================  KHALWSH  ==============================================*/
//int temp[]{3,4,5,4,3};
//int arr[5][5];
//vector<vector<bool>>vis(5);
//bool solve(bool turn){
//    bool done = false;
//    for(int i=0;i<5;i++){
//        for(int j = 0;j<vis[i].size();j++){
//            if(!vis[i][j]){
//                if(turn){
//
//                }else{
//
//                }
//            }
//        }
//    }
//}
signed main() {
    khaled
//    int k = 0;
//    for(auto &val:temp){
//        vis[k] = vector<bool>(val);
//        k++;
//    }
//    for(int i=0;i<5;i++){
//        for(int j = 0;j<temp[i];j++){
//            char x ;
//            cin>>x;
//            arr[i][j]=x;
//        }
//    }
      int n;
    cin>>n;
    set<vector<int>>s;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((i^j)>n||(i^j)<1)continue;
            vector<int>v;
            v.emplace_back(i);
            v.emplace_back(j);
            v.emplace_back(i^j);
            sort(v.begin(),v.end());
            if(v[0]+v[1]<=v[2])continue;
            s.insert(v);
        }
    }

    cout<<s.size()<<line;
}