
#include <iostream>
using namespace std;

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int wt[100], val[100];

    cout << "Enter weights of items:\n";
    for (int i = 1; i <= n; i++) {
        cin >> wt[i];
    }

    cout << "Enter profits of items:\n";
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    int dp[101][101] = {0};

    // Dynamic Programming
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            if (wt[i] <= w) {
                dp[i][w] = max(
                    val[i] + dp[i - 1][w - wt[i]],
                    dp[i - 1][w]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "\nMaximum Profit = " << dp[n][W];

    return 0;
}
