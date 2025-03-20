#include <iostream>
using namespace std;

void display (int A[], int n)
{
    cout<<"[";
    for (int i = 0; i < n-1; i++)
    {
        cout<<A[i]<<", ";
    }
    cout<<A[n-1]<<"]\n";
}
void inputArr(int A[], int n)
{
    cout<<"\n Start to enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
        cout<<"\n";
    }
    cout<<"The input array is:\n";
    display(A,n);
}
void findPeaksbyLS(int Arr1[], int Arr2[], int n)
{
    int i;
    if (n==1)
    {
        Arr2[0]=1;
    }
    else
    {
        for (i = 1; i < n-1; i++)
        {
            if ((Arr1[i]>Arr1[i-1]) && (Arr1[i]>Arr1[i+1]))
            {
                Arr2[i]=1;
            }
        }
        if (Arr1[n-1]>Arr1[n-2])
        {
            Arr2[n-1]=1;
        }
        if (Arr1[0]>Arr1[1])
        {
            Arr2[0]=1;
        }
    }
    cout<<"The final array to highlight peaks is:\n";
    display(Arr2,n);
}
int main()
{
    int n;
    cout<<"Number of values in array : ";
    cin>>n;
    int *A= new int[n]();
    inputArr(A,n);
    int *S= new int[n]();
    findPeaksbyLS(A,S,n);
    delete [] A;
    delete [] S;
}