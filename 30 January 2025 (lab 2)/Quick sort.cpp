#include <iostream>
using namespace std;

int partition(int A[], int low, int high)
{
    int pivot = A[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[high]);
    return i + 1;
}

void quickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(A, low, high);
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
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
    quickSort(A, 0, n - 1);
    cout << "Sorted array using Quick Sort is:\n[";
    for (int i = 0; i < n - 1; i++)
    {
        cout << A[i] << ", ";
    }
    cout << A[n - 1] << "]\n";
    delete[] A;
    return 0;
}