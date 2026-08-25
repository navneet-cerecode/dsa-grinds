#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> values(nums.begin(), nums.end());

        int multiplier = 1;

        // Check k, 2k, 3k, ... until the first missing multiple.
        while (values.find(multiplier * k) != values.end()) {
            multiplier++;
        }

        return multiplier * k;
    }
};

int main() {
    vector<pair<pair<vector<int>, int>, int>> tests = {
        {{{8, 2, 3, 4, 6}, 2}, 10},
        {{{1, 4, 7, 10, 15}, 5}, 5},
        {{{1}, 1}, 2},
        {{{2, 4, 6}, 2}, 8},
        {{{100}, 100}, 200},
        {{{3, 6, 12}, 3}, 9}
    };

    Solution solution;

    for (auto& test : tests) {
        vector<int>& nums = test.first.first;
        int k = test.first.second;
        int expected = test.second;
        int actual = solution.missingMultiple(nums, k);

        cout << actual << " (expected " << expected << ")\n";
    }

    return 0;
}
