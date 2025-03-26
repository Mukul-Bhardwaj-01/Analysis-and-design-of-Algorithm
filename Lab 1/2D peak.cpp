#include <iostream>
using namespace std;

void inputArr(int m, int n, int **Arr)
{
    cout << "Enter elements row-wise:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> Arr[i][j];
        }
    }
}

void printArr(int m, int n, int **Arr)
{
    cout << "[\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << Arr[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "]\n";
}

void findPeak(int **Arr, int m, int n, int **peaks)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bool isPeak = true;

            if (i > 0 && Arr[i][j] <= Arr[i - 1][j])
                isPeak = false;
            
            if (i < m - 1 && Arr[i][j] <= Arr[i + 1][j])
                isPeak = false;
            
            if (j > 0 && Arr[i][j] <= Arr[i][j - 1])
                isPeak = false;
            
            if (j < n - 1 && Arr[i][j] <= Arr[i][j + 1])
                isPeak = false;

            if (isPeak)
                peaks[i][j] = 1;
        }
    }
    printArr(m, n, peaks);
}

int main()
{
    int m, n;
    cout << "Enter matrix dimensions (rows and columns):\n";
    cin >> m >> n;

    int **Mountains = new int *[m];
    for (int i = 0; i < m; i++)
        Mountains[i] = new int[n];

    inputArr(m, n, Mountains);
    cout << "Input Matrix:\n";
    printArr(m, n, Mountains);

    int **peaks = new int *[m];
    for (int i = 0; i < m; i++)
        peaks[i] = new int[n]();

    cout << "Peak Matrix:\n";
    findPeak(Mountains, m, n, peaks);

    for (int i = 0; i < m; i++)
    {
        delete[] Mountains[i];
        delete[] peaks[i];
    }
    delete[] Mountains;
    delete[] peaks;

    return 0;
}
