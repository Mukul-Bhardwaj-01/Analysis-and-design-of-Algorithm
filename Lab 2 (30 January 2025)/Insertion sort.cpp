#include <iostream>
using namespace std;

void insertionSort(int n, int A[])
{
    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
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
    insertionSort(n, A);
    cout << "Sorted array using Insertion Sort is:\n[";
    for (int i = 0; i < n - 1; i++)
    {
        cout << A[i] << ", ";
    }
    cout << A[n - 1] << "]\n";

    delete[] A;
    return 0;
}
