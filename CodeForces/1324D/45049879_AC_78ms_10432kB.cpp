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
struct linked_list_node{
    int data{};
    linked_list_node*next{};
    linked_list_node(int value)
    {
        data=value;
        next=nullptr;
    }
};
class linked_list{
private:
    linked_list_node*head{};
    linked_list_node*tail{};
    int length=0;
public:
    //insert delete find reverse
    void insert(int value)
    {
        if(!length)
        {
            head=new linked_list_node(value);
            length++;
            head->next=nullptr;
        }
        else if(length==1)
        {
            tail=new linked_list_node{value};
            head->next=tail;
            tail->next=nullptr;
            length++;
        }
        else
        {
            //2 3 2 -->2
            tail->next=new linked_list_node(value);
            tail=tail->next;
            length++;
        }
    }
    void print()
    {
        linked_list_node*temp=head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<line;
    }
    bool find(int value)
    {
        //linear search
        linked_list_node*temp=head;
        while(temp)
        {
            if(temp->data==value)
                return true;
            temp=temp->next;
        }
        return false;
    }
    void reverse_iterative()
    {
        linked_list_node*prev=nullptr;
        linked_list_node*cur=head;
        tail=head;
        while(cur)
        {
            linked_list_node*save=cur->next;
            cur->next=prev;
            prev=cur;
            cur=save;
        }
        head=prev;
    }
    linked_list_node* reverse(linked_list_node* node)
    {
        if (node == nullptr)
            return nullptr;
        if (node->next == nullptr) {
            head = node;
            return node;
        }
        linked_list_node* node1 = reverse(node->next);
        node1->next = node;
        node->next = nullptr;
        return node;
    }
    void reverse_recursive()
    {
        tail=head;
        reverse(head);
        tail->next=nullptr;
    }
    void erase(int value)
    {
        if(length==0)
            return;
        else if(head->data==value)
        {
            linked_list_node*temp=head;
            head=head->next;
            temp->next=nullptr;
            delete temp;
            temp=nullptr;
            length--;
            return;
        }
        if(!find(value))
            return;
        linked_list_node*prev=nullptr;
        linked_list_node*cur=head;
        while(cur)
        {
            if(cur->data==value)
                break;
            prev=cur;
            cur=cur->next;
        }
        prev->next=cur->next;
        cur->next=nullptr;
        delete cur;
        length--;
    }
};
int binary_search(int pos,vector<long long>&v)
{
    int left=pos+1;
    int right=(int)v.size()-1;
    int res=-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(v[mid]+v[pos]>0)
        {
            res=mid;
            right=mid-1;
        }
        else
            left=mid+1;
    }
    return res;
}
int main() {
    khaled
    int n;
    cin>>n;
    vector<pair<long long,long long>>v(n);
    vector<long long>first(n);
    for(auto &val:first)
        cin>>val;
    vector<long long>second(n);
    for(auto &val:second)
        cin>>val;
    for(int i=0;i<n;i++)
        v[i]= make_pair(first[i],second[i]);

    vector<long long>difference;
    for(auto &val:v)
        difference.emplace_back(val.first-val.second);
    sort(difference.begin(),difference.end());

    long long final_res=0;//0 3 -2 5 -1//-2 -1 0 3 5
    for(int i=0;i<n;i++)
    {
        int siz=binary_search(i,difference);
        if(siz==-1)
            continue;
        final_res+=(n-siz);
    }
    cout<<final_res<<line;

}