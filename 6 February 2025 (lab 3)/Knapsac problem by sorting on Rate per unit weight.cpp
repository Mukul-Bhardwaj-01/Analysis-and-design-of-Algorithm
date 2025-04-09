#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int profit, weight, index;
    double fraction;
};

bool compareByRatio(Item a, Item b)
{
    return (double)a.profit / a.weight > (double)b.profit / b.weight;
}

void fractionalKnapsack(int W, Item arr[], int n)
{
    Item originalArr[n];
    for (int i = 0; i < n; i++)
        originalArr[i] = arr[i];
    sort(arr, arr + n, compareByRatio);
    int W_bought = 0;
    double total_profit = 0.0;
    double X[n] = {0}; 
    for (int i = 0; i < n; i++)
    {
        if (W_bought + arr[i].weight <= W)
        {
            W_bought += arr[i].weight;
            total_profit += arr[i].profit;
            X[arr[i].index] = 1;
        }
        else
        {
            double fraction = (double)(W - W_bought) / arr[i].weight;
            total_profit += arr[i].profit * fraction;
            X[arr[i].index] = fraction;
            W_bought = W;
            break;
        }
    }
    cout << "Total profit (sorted by profit/weight ratio): " << total_profit << endl;
    cout << "Selected items (X array): [";
    for (int i = 0; i < n - 1; i++)
        cout << X[i] << ", ";
    cout << X[n - 1] << "]" << endl;
}

int main()
{
    int n, W;
    cout << "Enter number of items and knapsack capacity: ";
    cin >> n >> W;
    Item arr[n];
    cout << "Enter profit and weight of each item:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].profit >> arr[i].weight;
        arr[i].index = i;
    }
    fractionalKnapsack(W, arr, n);
}