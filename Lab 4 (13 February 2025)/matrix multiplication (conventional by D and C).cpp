#include <iostream>
using namespace std;

const int SIZE = 4;
void Input2DMatrix(int matrix[SIZE][SIZE])
{
    cout << "Enter values into your matrix row wise:\n";
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
        {
            cout << "Enter value at matrix[" << i << "][" << j << "] : ";
            cin >> matrix[i][j];
        }
}

void displayMatrix(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "\n";
        for (int j = 0; j < SIZE; j++)
            cout << matrix[i][j] << "\t";
    }
    cout << endl;
}

void addMatrix(int A[2][2], int B[2][2], int result[2][2])
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            result[i][j] = A[i][j] + B[i][j];
}

void multiply2x2(int A[2][2], int B[2][2], int result[2][2])
{
    result[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    result[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    result[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    result[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];
}

void matrixMultiplication(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE])
{
    int A11[2][2], A12[2][2], A21[2][2], A22[2][2];
    int B11[2][2], B12[2][2], B21[2][2], B22[2][2];
    int C11[2][2] = {}, C12[2][2] = {}, C21[2][2] = {}, C22[2][2] = {};
    int temp1[2][2], temp2[2][2];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+2];
            A21[i][j] = A[i+2][j];
            A22[i][j] = A[i+2][j+2];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+2];
            B21[i][j] = B[i+2][j];
            B22[i][j] = B[i+2][j+2];
        }
    multiply2x2(A11, B11, temp1);
    multiply2x2(A12, B21, temp2);
    addMatrix(temp1, temp2, C11);
    multiply2x2(A11, B12, temp1);
    multiply2x2(A12, B22, temp2);
    addMatrix(temp1, temp2, C12);
    multiply2x2(A21, B11, temp1);
    multiply2x2(A22, B21, temp2);
    addMatrix(temp1, temp2, C21);
    multiply2x2(A21, B12, temp1);
    multiply2x2(A22, B22, temp2);
    addMatrix(temp1, temp2, C22);

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            C[i][j]     = C11[i][j];
            C[i][j+2]   = C12[i][j];
            C[i+2][j]   = C21[i][j];
            C[i+2][j+2] = C22[i][j];
        }
}

int main()
{
    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
    Input2DMatrix(A);
    Input2DMatrix(B);
    cout << "\nMatrix A:";
    displayMatrix(A);
    cout << "\nMatrix B:";
    displayMatrix(B);
    matrixMultiplication(A, B, C);
    cout << "\nResultant Matrix (A x B):";
    displayMatrix(C);
    return 0;
}
