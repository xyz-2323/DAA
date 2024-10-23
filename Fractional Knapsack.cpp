#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Class to represent an item with profit and weight
class Item {
public:
    int profit, weight;

    // Constructor
    Item(int p, int w) {
        profit = p;
        weight = w;
    }
};

// Function to compare items based on profit-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;  // Sort in decreasing order of ratio
}

// Function to calculate the maximum value in the knapsack
double fractionalKnapsack(int W, vector<Item>& arr) {
    // Sort items by profit-to-weight ratio
    sort(arr.begin(), arr.end(), compare);

    double final_value = 0.0;  // Variable to store the total value in knapsack

    // Traverse through the sorted items
    for (auto& item : arr) {
        if (W >= item.weight) {
            // Take the whole item
            final_value += item.profit;
            W -= item.weight;
        } else {
            // Take the fraction of the item that fits
            final_value += item.profit * ((double)W / item.weight);
            break;  // No more space left
        }
    }

    return final_value;
}

int main() {
    int n;
    cout << "Enter number of items:\n";
    cin >> n;

    vector<Item> arr;
    for (int i = 0; i < n; i++) {
        int profit, weight;
        cout << "Enter profit of item " << i + 1 << ":\n";
        cin >> profit;
        cout << "Enter weight of item " << i + 1 << ":\n";
        cin >> weight;
        arr.emplace_back(profit, weight);  // Add item to the vector
    }

    int W;
    cout << "Enter capacity of knapsack:\n";
    cin >> W;

    cout << "Maximum value in knapsack: " << fractionalKnapsack(W, arr) << endl;

    return 0;
}
