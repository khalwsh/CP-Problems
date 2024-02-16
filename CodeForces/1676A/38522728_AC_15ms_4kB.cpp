#include<iostream>
#include<sstream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string k;
        cin>>k;
        int sum_first=0;
        int sum_last=0;
        for(int i=0;i<3;i++)
        {
            int val;
            stringstream s;
            s<<k[i];
            s>>val;
            sum_first+=val;

        }
        for(int i=3;i<6;i++)
        {
            int val;
            stringstream s;
            s<<k[i];
            s>>val;
            sum_last+=val;
        }
        if(sum_first==sum_last)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }
}
