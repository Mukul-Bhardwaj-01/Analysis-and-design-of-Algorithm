#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int w = 0; w <= W; ++w)
        {
            if (wt[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);
    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; ++i) cin >> wt[i];

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; ++i) cin >> val[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    int maxProfit = knapsack(W, wt, val, n);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
