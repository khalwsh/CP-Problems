#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int prog=0,math=0,pe=0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i]==1)
            prog++;
        else if(arr[i]==2)
            math++;
        else
            pe++;
    }
    int w=min(min(pe,math),prog);
    cout<<min(min(pe,math),prog)<<endl;
    if(min(min(pe,math),prog)==0)
        return 0;
    else
    {
        int k=0,u=0,y=0;
        while(w--)
        {

            for( int i=k;i<n;i++)
            {
                if(arr[i]==1)
                {
                   cout<<i+1<<" ";
                   k=i+1;
                   break;
                }

            }
            for( int j=u;j<n;j++)
            {
                if(arr[j]==2)
                {
                   cout<<j+1<<" ";
                   u=j+1;
                   break;
                }

            }
            for( int m=y;m<n;m++)
            {
                if(arr[m]==3)
                {
                    cout<<m+1;
                    y=m+1;
                    break;
                }

            }
            cout<< endl;
        }
    }

}
