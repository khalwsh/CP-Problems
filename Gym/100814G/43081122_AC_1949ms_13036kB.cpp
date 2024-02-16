#include<bits/stdc++.h>
using namespace std;
#define line '\n'
#define khaled ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void merge(int arr[],int left,int mid,int right)
{
    int siz1=mid-left+1;
    int siz2=right-mid;
    int *arr1=new int[siz1];
    int *arr2=new int[siz2];
    for(int i=0;i<siz1;i++)
        arr1[i]=arr[left+i];
    for(int i=0;i<siz2;i++)
        arr2[i]=arr[mid+i+1];
    int pointer_orginal_array=left;
    int pointer_first_array=0,pointer_second_array=0;
    while(pointer_first_array<siz1&&pointer_second_array<siz2)
    {
        if(arr1[pointer_first_array]<arr2[pointer_second_array])
            arr[pointer_orginal_array++]=arr1[pointer_first_array++];
        else
            arr[pointer_orginal_array++]=arr2[pointer_second_array++];
    }
    while(pointer_first_array<siz1)
        arr[pointer_orginal_array++]=arr1[pointer_first_array++];
    while(pointer_second_array<siz2)
        arr[pointer_orginal_array++]=arr2[pointer_second_array++];
}
void merge_sort(int arr[],int left,int right)
{
    if(left>=right) {
        return;
    }
    int mid=left+(right-left)/2;
    merge_sort(arr,left,mid);
    merge_sort(arr,mid+1,right);
    merge(arr,left,mid,right);
}
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[(left + right) / 2];
        int i = left - 1;
        int j = right + 1;
        while (true) {
            do {
                i++;
            } while (arr[i] < pivot);
            do {
                j--;
            } while (arr[j] > pivot);
            if (i >= j) {
                break;
            }
            swap(arr[i], arr[j]);
        }
        quickSort(arr, left, j);
        quickSort(arr, j + 1, right);
    }
}
bool dikstra(long long needed_wisdom,vector<pair<int,pair<long long,long long>>>adj[],long long k,int n)
{
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;
    vector<long long>dist(n,INT64_MAX);
    dist[0]=0;
    pq.emplace(0,0);
    long long wisdom=0;
    while(!pq.empty())
    {
        int node=pq.top().second;
        long long cost=pq.top().first;
        pq.pop();
        if(dist[node]!=cost)
            continue;
        if(wisdom<=needed_wisdom)
        {
            for(auto &val:adj[node])
            {
                if(dist[val.first]>dist[node]+val.second.first&&val.second.second<=needed_wisdom)
                {
                    wisdom=val.second.second;
                    dist[val.first]=dist[node]+val.second.first;
                    pq.emplace(dist[val.first],val.first);
                }
            }
        }
    }
    return dist[n-1]<k;
}
int main() {
    khaled
    int t;
    cin>>t;
    while(t--) {
        int n;
        int m;
        long long k;
        cin >> n >> m >> k;
        vector<pair<int, pair<long long, long long>>> adj[n];//from index to first and the second.first equal to cost the second.second=wisdom
        for (int i = 0; i < m; i++) {
            int from, to;
            long long cost, wisdom;
            cin >> from >> to >> cost >> wisdom;
            from--,to--;
            adj[from].emplace_back(make_pair(to, make_pair(cost, wisdom)));
            adj[to].emplace_back(make_pair(from, make_pair(cost, wisdom)));
        }
        long long left = 0, right = 1e9 + 10;
        long long res = 0;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (dikstra(mid, adj, k, n)) {
                right = mid - 1;
                res = mid;
            } else
                left = mid + 1;
        }
        cout << ((right == 1e9+10) ? -1 : res) << line;
    }
}
