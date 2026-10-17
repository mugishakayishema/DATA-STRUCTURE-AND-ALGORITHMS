//Names:mugisha kayishema
//Reg number:224003729


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent a crop
struct Crop {
    string name;
    int space;   // land required (m²)
    int value;   // nutrition units (e.g., Vitamin A)
};

// Function to solve Knapsack problem
int knapsack(vector<Crop>& crops, int maxSpace) {
    int n = crops.size();
    vector<vector<int>> dp(n + 1, vector<int>(maxSpace + 1, 0));

    // Build table dp[][] in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= maxSpace; w++) {
            if (crops[i - 1].space <= w) {
                dp[i][w] = max(crops[i - 1].value + dp[i - 1][w - crops[i - 1].space],
                    dp[i - 1][w]);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][maxSpace];
}

int main() {
    // Example crops
    vector<Crop> crops = {
        {"Carrots", 3, 8},
        {"Amaranth", 2, 6},
        {"Tomatoes", 4, 4}
    };

    int maxSpace = 10; // total land available (m²)

    cout << "Maximum nutrition units achievable: "
        << knapsack(crops, maxSpace) << endl;

    return 0;
}
