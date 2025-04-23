#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int matrixChainOrder(vector<int>& p, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // l is chain length
    for (int len = 2; len < n; ++len)
    {
        for (int i = 1; i < n - len + 1; ++i)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k)
            {
                int cost = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    return dp[1][n-1];
}

int main()
{
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> dimensions(n + 1);
    cout << "Enter dimensions array (length " << n + 1 << "):\n";
    for (int i = 0; i <= n; ++i)
        cin >> dimensions[i];

    int minCost = matrixChainOrder(dimensions, n + 1);
    cout << "Minimum number of multiplications: " << minCost << endl;

    return 0;
}
