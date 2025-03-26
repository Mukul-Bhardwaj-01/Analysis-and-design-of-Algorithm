#include <iostream>
using namespace std;

void bubbleSort(int n, int A[])
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (A[j]>A[j+1])
            {
                swap(A[j],A[j+1]);
            }
        }
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
    
    bubbleSort(n, A);

    cout<<"Sorted array using bubble sort is:\n";
    cout<<"[";
    for (int i = 0; i < n-1; i++)
    {
        cout<<A[i]<<", ";
    }
    cout<<A[n-1]<<"]";
    delete[] A;
}
