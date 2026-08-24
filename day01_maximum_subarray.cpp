#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int maximumSubarray(const vector<int>& nums) {
    int currentSum = nums[0];
    int bestSum = nums[0];

    for (int i = 1; i < static_cast<int>(nums.size()); i++) {
        // Either extend the previous subarray or restart at this value.
        currentSum = max(nums[i], currentSum + nums[i]);
        bestSum = max(bestSum, currentSum);
    }

    return bestSum;
}

int main() {
    vector<pair<vector<int>, int>> tests = {
        {{-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6},
        {{1}, 1},
        {{5, 4, -1, 7, 8}, 23},
        {{-5, -2, -8}, -2},
        {{-2, -1}, -1},
        {{1, -2, 3, 4, -1}, 7}
    };

    for (const auto& test : tests) {
        int actual = maximumSubarray(test.first);
        int expected = test.second;

        cout << actual << " (expected " << expected << ")\n";
    }

    return 0;
}
