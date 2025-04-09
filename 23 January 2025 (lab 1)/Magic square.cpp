#include <iostream>
using namespace std;

void printSquare(int **matrix, int n)
{
    cout << "[\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "]\n";
}

void magicSquare(int n, int **matrix)
{
    int i = 0, j = n / 2;

    for (int num = 1; num <= n * n; num++)
    {
        matrix[i][j] = num;
        int new_i = (i - 1 + n) % n;
        int new_j = (j + 1) % n;

        if (matrix[new_i][new_j] != 0)
        {
            i = (i + 1) % n;
        }
        else
        {
            i = new_i;
            j = new_j;
        }
    }
    printSquare(matrix, n);
}

int main()
{
    int n;
    cout << "Enter an odd length for the magic square: ";
    cin >> n;

    if (n % 2 == 0)
    {
        cout << "Magic square only works for odd numbers.\n";
        return 0;
    }

    int **msquare = new int *[n];
    for (int i = 0; i < n; i++)
    {
        msquare[i] = new int[n]();
    }
    magicSquare(n, msquare);

    for (int i = 0; i < n; i++)
    {
        delete[] msquare[i];
    }
    delete[] msquare;

    return 0;
}