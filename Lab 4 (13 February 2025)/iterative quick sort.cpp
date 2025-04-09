#include <iostream>
#include <stack>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortIterative(int arr[], int l, int h)
{
    stack<int> s;

    s.push(l);
    s.push(h);
    while (!s.empty())
    {
        h = s.top(); s.pop();
        l = s.top(); s.pop();
        int p = partition(arr, l, h);
        if (p - 1 > l)
        {
            s.push(l);
            s.push(p - 1);
        }
        if (p + 1 < h)
        {
            s.push(p + 1);
            s.push(h);
        }
    }
}

int main()
{
    int arr[] = {4, 2, 6, 9, 1, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSortIterative(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
