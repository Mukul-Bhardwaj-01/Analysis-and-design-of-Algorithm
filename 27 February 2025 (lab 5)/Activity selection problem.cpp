#include <iostream>
using namespace std;

struct Activity {
    int start, end;
};

void selectionSort(Activity arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].end < arr[minIdx].end)
            {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void activitySelection(Activity arr[], int n)
{
    selectionSort(arr, n);
    cout << "Selected activities (start, end):\n";
    int lastEndTime = arr[0].end;
    cout << "(" << arr[0].start << ", " << arr[0].end << ")\n";

    for (int i = 1; i < n; i++)
    {
        if (arr[i].start >= lastEndTime)
        {
            cout << "(" << arr[i].start << ", " << arr[i].end << ")\n";
            lastEndTime = arr[i].end;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;
    Activity arr[n];
    cout << "Enter start and end times of activities:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].start >> arr[i].end;
    }
    activitySelection(arr, n);
    return 0;
}