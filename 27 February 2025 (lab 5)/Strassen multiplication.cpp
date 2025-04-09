#include <iostream>
using namespace std;

void addMatrix(int A[2][2], int B[2][2], int C[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrix(int A[2][2], int B[2][2], int C[2][2])
{
    for (int i = 0; i < 2; i++)
    {   for (int j = 0; j < 2; j++)
        {   
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassenMultiply(int A[2][2], int B[2][2], int C[2][2])
{
    int M1[2][2], M2[2][2], M3[2][2], M4[2][2], M5[2][2], M6[2][2], M7[2][2];
    int temp1[2][2], temp2[2][2];

    addMatrix(A, A, temp1);
    addMatrix(B, B, temp2);
    strassenMultiply(temp1, temp2, M1);
    addMatrix(A, A, temp1);
    strassenMultiply(temp1, B, M2);
    subtractMatrix(B, B, temp1);
    strassenMultiply(A, temp1, M3);
    subtractMatrix(B, B, temp1);
    strassenMultiply(A, temp1, M4);
    addMatrix(A, A, temp1);
    strassenMultiply(temp1, B, M5);
    subtractMatrix(A, A, temp1);
    addMatrix(B, B, temp2);
    strassenMultiply(temp1, temp2, M6);
    subtractMatrix(A, A, temp1);
    addMatrix(B, B, temp2);
    strassenMultiply(temp1, temp2, M7);
    addMatrix(M1, M4, temp1);
    subtractMatrix(temp1, M5, temp2);
    addMatrix(temp2, M7, C);
    addMatrix(M3, M5, C);
    addMatrix(M2, M4, C);
    addMatrix(M1, M3, temp1);
    subtractMatrix(temp1, M2, temp2);
    addMatrix(temp2, M6, C);
}

int main()
{
    int A[2][2], B[2][2], C[2][2];

    cout << "Enter elements of first 2x2 matrix:\n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> A[i][j];
        }    
    }
    cout << "Enter elements of second 2x2 matrix:\n";
    for (int i = 0; i < 2; i++)
    {   
        for (int j = 0; j < 2; j++)
        {
            cin >> B[i][j];
        }
    }
    strassenMultiply(A, B, C);

    cout << "Resultant matrix after Strassen's multiplication:\n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {    
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}