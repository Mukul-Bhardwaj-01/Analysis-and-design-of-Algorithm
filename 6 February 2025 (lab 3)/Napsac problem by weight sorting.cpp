#include <iostream>
using namespace std;

void inputArr(int Arr[][2], int n)
{
    cout<<"Enter the profit and weight associated to that profit :\n";
    for (int i = 0; i < n; i++)
    {
        cout<<"\nEnter profit amount : ";
        cin>>Arr[i][0];
        cout<<"\nEnter weight of item : ";
        cin>>Arr[i][1];
    }
    cout<<"\nInput chart of profit and weight is:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<Arr[i][0]<<"\t"<<Arr[i][1]<<endl;
    }
    
}

void sortWeight(int Arr[][2], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (Arr[j][1] > Arr[maxIdx][1])
            {
                maxIdx = j;
            }
        }
        swap(Arr[i][1], Arr[maxIdx][1]);
        swap(Arr[i][0], Arr[maxIdx][0]);
    }

    cout << "\nSorted chart of profit and weight is:\n";
    for (int i = 0; i < n; i++) {
        cout << Arr[i][0] << "\t" << Arr[i][1] << endl;
    }
}

int main()
{
    int n, W, W_bought=0, total_profit=0, i=0, j;
    cout<<"Number of available items : ";
    cin>>n;
    int itemChart[n][2], X[n][3];
    inputArr(itemChart,n);

    //Sorting on basis on profit (non-increasing)
    sortWeight(itemChart,n);
    
    //Inserting values into the X array
    for (int a = 0; a < n; a++)
    {
        X[a][0]=itemChart[a][0];
        X[a][1]=itemChart[a][1];
        X[a][2]=0;
    }
    
    cout<<"Enter the capacity of your sack : ";
    cin>>W;
    while (W-W_bought > 0 && i<n)
    {
        if (itemChart[i][1]>W-W_bought)
        {
            total_profit=(itemChart[i][0]/itemChart[i][1])*W;
            W_bought=W;
            break;
        }
        total_profit += itemChart[i][0];
        W_bought += itemChart[i][1];
        i++;
    }
    
    cout<<"Weight of materials bought is : "<<W_bought<<endl;
    cout<<"Total profit from these items is : "<<total_profit;

/*j=i-1;
    while (j>=0)
    {
        for(int k=0; k<n; k++)
        {
            X[k][2]=1;
        }
        j--;
    }
*/    
    
}