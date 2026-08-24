#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int maximumSubarraySumOfSizeK(const vector<int>& nums, int k) {
    int n = static_cast<int>(nums.size());

    // Phase 1: calculate the first complete window.
    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    int maximumSum = windowSum;

    // Phase 2: slide right by removing one value and adding one value.
    for (int i = k; i < n; i++) {
        int leaving = nums[i - k];
        int entering = nums[i];

        windowSum = windowSum - leaving + entering;
        maximumSum = max(maximumSum, windowSum);
    }

    return maximumSum;
}

int main() {
    vector<pair<pair<vector<int>, int>, int>> tests = {
        {{{2, 1, 5, 1, 3, 2}, 3}, 9},
        {{{4, 2, 1, 7, 8, 1, 2, 8, 1, 0}, 3}, 16},
        {{{-4, -2, -7, -1}, 2}, -6},
        {{{5}, 1}, 5},
        {{{1, 2, 3}, 3}, 6},
        {{{1, -1, 5, -2, 3}, 2}, 4}
    };

    for (const auto& test : tests) {
        const vector<int>& nums = test.first.first;
        int k = test.first.second;
        int expected = test.second;
        int actual = maximumSubarraySumOfSizeK(nums, k);

        cout << "k = " << k << " -> " << actual
             << " (expected " << expected << ")\n";
    }

    return 0;
}
