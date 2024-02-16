#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    khaled
    int n;
    int q;
    cin>>n>>q;
    map<int,set<int>>number_to_box;//number to boxes query three
    map<int,multiset<int>>add_to_box;//query one
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int i,j;
            cin>>i>>j;
            add_to_box[j].insert(i);
            number_to_box[i].insert(j);
        }
        else if(type==2)
        {
            int i;
            cin>>i;
            for(auto &val:add_to_box[i])
                cout<<val<<" ";
            cout<<line;
        }
        else
        {
            int i;
            cin>>i;
            for(auto &val:number_to_box[i])
                cout<<val<<" ";
            cout<<line;
        }
    }
}