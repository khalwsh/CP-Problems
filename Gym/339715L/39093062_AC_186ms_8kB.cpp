#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int b;
    int a;
    queue<int>q;
    while(n--)
    {
      cin>>b;
      cin>>a;
      if(b==1)
      {
          q.push(a);
      }
      else
      {
          if(q.front()==a)
            cout<<"Yes"<<endl;
          else
            cout<<"No"<<endl;
            q.pop();

      }
    }

}
