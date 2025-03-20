#include <iostream>
using namespace std;

void Input2DMatrix(int matrix[4][4])
{
    cout<<"Enter values into your matrix row wise:\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<"\nEnter value at matrix["<<i<<"]["<<j<<"] : ";
            cin>>matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        cout<<"\n";
        for (int j = 0; j < 4; j++)
        {
            cout<<matrix[i][j]<<"\t";
        }
    }
    cout<<endl;
}

void matrixMultiplication(int A[4][4], int B[4][4], int C[4][4])
{
    int temp=0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            temp = temp  ;
        }
        
    }
    
}

int main()
{
    int A[4][4], B[4][4], C[4][4];
    Input2DMatrix(A);
    Input2DMatrix(B);
    cout<<"The matrices that have been input for multiplication are: \n";
    displayMatrix(A);
    displayMatrix(B);
}