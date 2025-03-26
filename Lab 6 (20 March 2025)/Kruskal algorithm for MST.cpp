#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2*i +1;
    int right = 2*i +2;

    if(left<n && arr[left]<arr[smallest])
    {
        smallest=left;
    }
    if (right<n && arr[right]<arr[smallest])
    {
        smallest=right;
    }
    
    if (smallest!=i)
    {
        swap(arr[i],arr[smallest]);
        heapify(arr, n, smallest);
    }
    
}

void minheap(int heap[], int n)
{
    for (int i = n/2-1; i >=0 ; i--)
    {
        heapify(heap,n,i);
    }
}

int main()
{
    int E[8][3] = {{1,2,1}, {1,3,9}, {2,4,4}, {2,6,6}, {3,4,8}, {3,5,7}, {4,5,10}, {5,6,2}};
    int edgeWtHeap[8]={1, 9, 4, 6, 8, 7, 10, 2};
    minheap(edgeWtHeap,8);
    cout<<"[";
    for (int i = 0; i < 8; i++)
    {
        cout<<edgeWtHeap[i]<<", ";
    }
    cout<<"]";
}