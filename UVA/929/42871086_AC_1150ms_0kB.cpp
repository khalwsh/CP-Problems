#include<bits/stdc++.h>
#include<chrono>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
/*void my_swap(int &a,int &b)
{
    a^=b;// a has a^b value stored in it
    b^=a;//now b^a--->from the last line b^a^b which will be a cause of the property so b has value of a
    a^=b;//now a has value of a^b then make a^b -->b has value of a from last operation then a^a^b equal to b
    //take by ref because I want the change being done actually on them not a copy
    //i will preform xor swaping it's much more efficent
    //nice property about xor if a^a the result equal zero
    //swaping done effiecnt because xor is much more faster than making a temp variable and swap
}
void selection_sort(int arr[],int size)
{
    //the array is sent by refernce so the sorting is being acually done in the data it's self
    //the array couldn't be passed by value
    //this algorithm of sorting making n rounds in every round choose the ith smallest element and place it in it's right postion
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[i])
                my_swap(arr[j],arr[i]);
        }
    }
    //time complexity is o(n^2)
    //space complexity is o(1)
    //this algorithm isn't efficent :)
}
void bubble_sort(int arr[],int size)
{
    //the array is sent by refernce so the sorting is being acually done in the data it's self
    //the array couldn't be passed by value
    //this algorithm of sorting making n rounds in every round if there is two consegative elements which are in wrong postion from each other
    //it makes them in right order
    for(int i=0;i<size;i++)
    {
        for(int j=0;j+1<size;j++)
        {
            if(arr[j]>arr[j+1])
                my_swap(arr[j],arr[j+1]);
        }
    }
    //time complexity is o(n^2)
    //space complexity is o(1)
    //this algorithm isn't effcient :)
}
void insertion_sort(int arr[],int size)
{
    //the array is sent by refernce so the sorting is being acually done in the data it's self
    //the array couldn't be passed by value
    //this algorithm of sorting is insert the element in it's right postion in a new array or in the same array
    for(int i=0;i<size;i++)//o(n(1+1+n(1+1))//o(2n^2+2n)
    {
        int pointer=i;
        int j=i-1;
        while(j>=0&&arr[pointer]<arr[j])
        {
            my_swap(arr[pointer--],arr[j]);
            j--;
        }
    }
    //best case omega(n)
    //time complexity is o(n^2)
    //space complexity is o(1)
    //this algorithm isn't effcient :)
}
void do_project()
{
    again:
    int n;
    cout<<"Enter the size of array:"<<flush;//using flush to force the output to the screen and not to go to a buffer-->temp memory
    cin>>n;
    int *arr=new int[n];//declaring an array
    for(int i=0;i<n;i++)
    {
        //creating random elements in the array
        // i could specify the range of random elements just take the mod and add the begin of the range
        //[3,10000]
        //start + rand % (end+1)
        //just for knowing rand has limited randomness i can use random library but rand is simpler
        //srand(time(nullptr));
        arr[i]=3+rand()%10001;
        //generate random elements form 0 to 32000
        //start to rand %(end+1)
        //arr[i]+=counter++;
    }
    wrong_input:
    cout<<"enter the sort type:"<<flush;//using flush because the output instead of going the screen it going to internal buffer
    //flush operation force output of going to the screen
    cout<<line<<"1)selection sort"<<"\t"<<"2)bubble sort\t"<<"3)insertion sort"<<line<<flush;
    int type;
    cin>>type;//type of sort
    if(!(type==1||type==2||type==3))//if the type not equal 1,2,3 then this is a wrong input so i make a go statement to return to the type again
        //to garante it's a valid input
    {
        cout<<"invalid input"<<flush;
        cout<<line;
        goto wrong_input;
    }
    else
    {
        //to calculate the time the operation of sorting take we can get the current
        // time before operation and current time after the substract them
        //we use the high_resolution_clock from the chrono library to get the current time before and after calling the function myFunction().
        // We then calculate the duration between these two times and print the result in microseconds.
        chrono::time_point<chrono::high_resolution_clock> start = chrono::high_resolution_clock::now(); // get start time
        if(type==1)
            selection_sort(arr,n);//calling function;
        else if(type==2)
            bubble_sort(arr,n);
        else if(type==3)
            insertion_sort(arr,n); // call the function to be timed
        chrono::time_point<chrono::high_resolution_clock> stop = chrono::high_resolution_clock::now(); // get stop time
        // In this case, the high_resolution_clock::now() function returns an object of type time_point<high_resolution_clock>
        // and the duration_cast template function returns an object of type duration<long long, ratio<1, 1000000>>
        auto duration = duration_cast<chrono::mic roseconds>(stop - start); // calculate duration in microseconds
        //auto is a datatype that figure out itself from the r value
        cout<<"the operation of sorting take time of:"<<duration.count()<<" microseconds"<<line<<flush;
    }
    cout<<"array with size["<<n<<"] after being sorted:"<<line<<flush;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" "<<flush;//printing the array;
    cout<<endl;
    cout<<"if you want to go another round choose one else choose zero:";
    bool yalla;cin>>yalla;
    if(yalla)
        goto again;
}*/
#define  int long long
bool valid(int i,int j,int n,int m)
{
    return i>=0&&i<n&&j>=0&&j<m;
}
int dikstra(int n,int m,vector<vector<int>>&v)
{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({v[0][0],{0,0}});
    vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
    dist[0][0]=v[0][0];
    while(!pq.empty())
    {
        int cost=pq.top().first;
        int row=pq.top().second.first;
        int col=pq.top().second.second;
        pq.pop();
        int dx[]{1,-1,0,0};
        int dy[]{0,0,1,-1};
        for(int i=0;i<4;i++)
        {
            int cur_row=row+dx[i];
            int cur_col=col+dy[i];
            if(valid(cur_row,cur_col,n,m)&&dist[cur_row][cur_col]>cost+v[cur_row][cur_col])
            {
                dist[cur_row][cur_col]=cost+v[cur_row][cur_col];
                pq.push({dist[cur_row][cur_col],{cur_row,cur_col}});
            }
        }
    }
    return dist[n-1][m-1];
}
signed main() {
    khaled
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int m;
        cin>>n>>m;
        vector<vector<int>>v(n,vector<int>(m));
        for(auto &val:v)
            for(auto &vv:val)
                cin>>vv;
        cout<<dikstra(n,m,v);
        cout<<line;
    }
}