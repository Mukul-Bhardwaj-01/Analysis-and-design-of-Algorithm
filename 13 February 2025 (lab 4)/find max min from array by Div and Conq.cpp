#include <iostream>
using namespace std;

struct Result {
    int min;
    int max;
};

Result findMinMax(int arr[], int low, int high)
{
    Result res, left, right;
    if (low == high)
    {
        res.min = res.max = arr[low];
        return res;
    }

    if (high == low + 1)
    {
        if (arr[low] < arr[high])
        {
            res.min = arr[low];
            res.max = arr[high];
        } else
        {
            res.min = arr[high];
            res.max = arr[low];
        }
        return res;
    }

    int mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);
    res.min = min(left.min, right.min);
    res.max = max(left.max, right.max);
    return res;
}

int main()
{
    int arr[] = {3, 5, 1, 8, 2, 9, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    Result res = findMinMax(arr, 0, n - 1);

    cout << "Minimum element: " << res.min << endl;
    cout << "Maximum element: " << res.max << endl;
    return 0;
}