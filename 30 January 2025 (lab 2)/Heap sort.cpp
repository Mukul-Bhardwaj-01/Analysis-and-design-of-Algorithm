#include <iostream>
using namespace std;

void heapify(int n, int i, int Arr[])
{
    int largest = i;
    int left=2*i+1;
    int right=2*i+2;

    if (left<n && Arr[largest]<Arr[left])
    {
        largest=left;
    }
    if (right<n && Arr[largest]<Arr[right])
    {
        largest=right;
    }
    if (largest!=i)
    {
        swap(Arr[i],Arr[largest]);
        heapify(n,largest,Arr);
    }
    
}

void heapsort(int n, int Arr[])
{
    for (int i = n/2-1; i >=0; i--)
    {
        heapify(n,i, Arr);
    }
    for (int i = n-1; i >0; i--)
    {
        swap(Arr[0],Arr[i]);
        heapify(i,0,Arr);
    }
}

int main()
{
    int n;
    cout<<"Number of elements in your array: ";
    cin>>n;
    int *A = new int[n];
    cout<<"Enter elements:\n";
    for (int i = 0; i <n; i++)
    {
        cin>>A[i];
    }
    
    heapsort(n, A);

    cout<<"Sorted array using heapsort is:\n";
    cout<<"[";
    for (int i = 0; i < n-1; i++)
    {
        cout<<A[i]<<", ";
    }
    cout<<A[n-1]<<"]";
    delete[] A;    
}