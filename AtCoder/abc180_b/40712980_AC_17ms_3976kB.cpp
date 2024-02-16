#include<bits/stdc++.h>
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main() {
    khaled
    long long n;
    cin>>n;
    vector<long long>v(n);
    long long summation=0;
    long long my_max=INT_MIN;
    long long another=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        v[i]=abs(v[i]);
        summation+=v[i];
        my_max=max(my_max,v[i]);
        another+=v[i]*v[i];
    }
    cout<<summation;
    cout<<line;
    cout<<fixed<<showpoint<<setprecision(15)<<sqrt(another);
    cout<<line<<noshowpoint<<my_max;
}