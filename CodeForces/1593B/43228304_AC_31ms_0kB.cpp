#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int t;
    string  n;
    long long s=0;
    cin>>t;
    while(t--){
        s=0;
        cin>>n;
        for(int i=0;i<n.size();i++){
            for(int j=i+1;j<n.size();j++)
                if(((n[i]-'0')*10+(n[j]-'0'))%25==0)
                    s=(int)n.size()-i-2;
        }
        cout<<s<<endl;
        n.clear();
    }
}