#include <iostream>
using namespace std;

void selectionSort(int n, int A[])
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(A[i], A[minIndex]);
        }
    }
}

int main()
{
    int n;
    cout << "Number of elements in your array: ";
    cin >> n;
    int *A = new int[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    selectionSort(n, A);
    cout << "Sorted array using Selection Sort is:\n[";
    for (int i = 0; i < n - 1; i++)
    {
        cout << A[i] << ", ";
    }
    cout << A[n - 1] << "]\n";
    delete[] A;
    return 0;
}
