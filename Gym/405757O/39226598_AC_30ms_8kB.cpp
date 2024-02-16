#include<iostream>
#include<map>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
    FAST
    string code;
    cin>>code;
    //string arr[8] {""};
    //int k=0;
    //int j=0;
    map<string,int>mp;
    /*khaled:
        for(int i=k; i<k+10; i++)
        {
            arr[j]+=code[i];
        }
        if(k<80)
        {
            k+=10;
            j++;
            goto khaled;
        }*/
    string m;
    for(int i=0; i<10; i++)
    {
        cin>>m;
        mp[m]=i;
    }
    string l;
    auto it=mp.find(m);
    m.clear();
    for(int i=0; i<8; i++)
    {
        for(int j=10*i; j<10*i+10; j++)
            m+=code[j];
            //cout<<m<<endl;
        it=mp.find(m);
        m.clear();
        l+=to_string(it->second);
    }
    cout<<l;

}
