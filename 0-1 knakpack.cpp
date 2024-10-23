#include <iostream>
#include <vector>
using namespace std;

pair<int, vector<int>> knapsack_01(int n, vector<int>& values, vector<int>& weights, int W) {
    // Create a 2D DP array to store the maximum value at each n, w
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the DP table
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0) {  // Base case: no items or no capacity
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {  // If item i can be included
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];  // Item i cannot be included
            }
        }
    }

    // To find selected items
    vector<int> selected_items;
    int w = W;
    for (int i = n; i > 0; --i) {
        if (dp[i][w] != dp[i - 1][w]) {  // Item i is included
            selected_items.push_back(i - 1);  // Append the index of the selected item
            w -= weights[i - 1];
        }
    }

    return {dp[n][W], selected_items};
}

int main() {
    // Taking input from the user
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> values(n), weights(n);
    cout << "Enter the values of the items separated by space: ";
    for (int i = 0; i < n; ++i) cin >> values[i];

    cout << "Enter the weights of the items separated by space: ";
    for (int i = 0; i < n; ++i) cin >> weights[i];

    int W;
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> W;

    // Getting the maximum value and selected items
    pair<int, vector<int>> result = knapsack_01(n, values, weights, W);

    // Output results
    cout << "Maximum value: " << result.first << endl;
    cout << "Selected items (0-indexed): ";
    for (int i : result.second) cout << i << " ";
    cout << endl;

    return 0;
}
