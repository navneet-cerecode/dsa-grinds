#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int binarySearchRevision(const vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (nums[middle] == target) {
            return middle;
        }

        if (nums[middle] > target) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    return -1;
}

int main() {
    vector<pair<pair<vector<int>, int>, int>> tests = {
        {{{-1, 0, 3, 5, 9, 12}, 9}, 4},
        {{{-1, 0, 3, 5, 9, 12}, 2}, -1},
        {{{5}, 5}, 0},
        {{{5}, -2}, -1},
        {{{1, 3}, 3}, 1},
        {{{1, 3}, 1}, 0},
        {{{1, 3, 5, 7}, 8}, -1}
    };

    for (const auto& test : tests) {
        const vector<int>& nums = test.first.first;
        int target = test.first.second;
        int expected = test.second;
        int actual = binarySearchRevision(nums, target);

        cout << actual << " (expected " << expected << ")\n";
    }

    return 0;
}
