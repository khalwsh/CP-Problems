#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int arr[N];
        int min1=2147483647;
        int  sum_odd=0,sum_even=0;
        int m=0;
        if(N%2==0)
        {
            for(int i=0; i<N; i++)
            {
                cin>>arr[i];
                if(arr[i]<min1)
                {
                    min1=arr[i];
                    m=i;
                }

            }
            if(m%2!=0)
                cout<<"Mike";
            else
                cout<<"Joe";
            cout<<endl;

        }
        else
        {
            for(int i=0;i<N;i++)
            cin>>arr[i];


         cout<<"Mike"<<endl;

        }

    }
}
