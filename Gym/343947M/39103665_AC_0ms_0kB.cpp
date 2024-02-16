#include<iostream>
#include<set>
#include<map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a;

        map<int,int,greater<int>>mp;
        for(int i=0; i<4; i++)
        {
            cin>>a;
            mp[a]=i;
        }


        map<int,int>::iterator it=mp.begin();
        if(it->second==0)
            cout<<"Hussien ";
        else if(it->second==1)
            cout<<"Atef ";
        else if(it->second==2)
            cout<<"Karemo ";
        else
            cout<<"Ezzat ";
        it++;
        if(it->second==0)
            cout<<"Hussien ";
        else if(it->second==1)
            cout<<"Atef ";
        else if(it->second==2)
            cout<<"Karemo ";
        else
            cout<<"Ezzat ";
        cout<<endl;





    }


}
