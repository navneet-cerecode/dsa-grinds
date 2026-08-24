#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int maxProfit(const vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }

    int minimumPrice = prices[0];
    int bestProfit = 0;

    for (int price : prices) {
        // The best sale today uses the cheapest price seen so far.
        minimumPrice = min(minimumPrice, price);
        int currentProfit = price - minimumPrice;
        bestProfit = max(bestProfit, currentProfit);
    }

    return bestProfit;
}

int main() {
    vector<pair<vector<int>, int>> tests = {
        {{7, 1, 5, 3, 6, 4}, 5},
        {{7, 6, 4, 3, 1}, 0},
        {{1, 2, 3, 4, 5}, 4},
        {{2, 4, 1}, 2},
        {{3, 3, 3}, 0},
        {{5}, 0},
        {{}, 0}
    };

    for (const auto& test : tests) {
        int actual = maxProfit(test.first);
        int expected = test.second;

        cout << actual << " (expected " << expected << ")\n";
    }

    return 0;
}
