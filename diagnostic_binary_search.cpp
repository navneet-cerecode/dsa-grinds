#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int searchTarget(const vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;

    while (left <= right) {
        // This form avoids the overflow risk of (left + right) / 2.
        int middle = left + (right - left) / 2;

        if (nums[middle] == target) {
            return middle;
        }

        if (nums[middle] > target) {
            // The target can only be to the left of middle.
            right = middle - 1;
        } else {
            // The target can only be to the right of middle.
            left = middle + 1;
        }
    }

    return -1;
}

int main() {
    vector<pair<pair<vector<int>, int>, int>> tests = {
        {{{-1, 0, 3, 5, 9, 12}, 9}, 4},
        {{{-1, 0, 3, 5, 9, 12}, 2}, -1},
        {{{2, 4, 6, 8, 10, 12, 14}, 12}, 5},
        {{{2, 4, 6, 8, 10, 12, 14}, 5}, -1},
        {{{5}, 5}, 0},
        {{{5}, -2}, -1}
    };

    for (const auto& test : tests) {
        const vector<int>& nums = test.first.first;
        int target = test.first.second;
        int expected = test.second;
        int actual = searchTarget(nums, target);

        cout << "target " << target << " -> " << actual
             << " (expected " << expected << ")\n";
    }

    return 0;
}
