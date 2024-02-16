#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int chest=0,biceps=0,back1=0;
    for(int i=0; i<n; i++)
        cin>>arr[i];

    for(int i=0; i<n; i++)
    {
        if(i%3==0)
            chest+=arr[i];
        else if(i%3==1)
            biceps+=arr[i];
        else
            back1+=arr[i];
    }
    if(max(chest,max(biceps,back1))==chest)
        cout<<"chest";
    else if(max(chest,max(biceps,back1))==biceps)
        cout<<"biceps";
    else if(max(chest,max(biceps,back1))==back1)
        cout<<"back";


}
