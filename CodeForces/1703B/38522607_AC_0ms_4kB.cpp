#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int length_string;
        cin>>length_string;
        string s;
        cin>>s;
        bool k=1;
        int ballons=length_string;
        for(int i=length_string-1;i>=0;i--)
        {
            k=1;
          for(int j=i-1;j>=0;j--)
          {

              if(s[i]!=s[j])
                k=1;
              else
              {
                  k=0;
                  break;
              }
          }
          if(k)
          {
              ballons++;
          }
        }
        cout<<ballons<<endl;
    }
}
