#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

bool containsDuplicate(const vector<int>& nums) {
    unordered_set<int> seen;

    for (int value : nums) {
        // Finding a previously seen value proves a duplicate exists.
        if (seen.find(value) != seen.end()) {
            return true;
        }

        seen.insert(value);
    }

    return false;
}

int main() {
    vector<pair<vector<int>, bool>> tests = {
        {{1, 2, 3, 1}, true},
        {{1, 2, 3, 4}, false},
        {{1, 1, 1, 3}, true},
        {{-1, -2, -1}, true},
        {{5}, false},
        {{}, false}
    };

    for (const auto& test : tests) {
        bool actual = containsDuplicate(test.first);
        bool expected = test.second;

        cout << (actual ? "true" : "false")
             << " (expected " << (expected ? "true" : "false") << ")\n";
    }

    return 0;
}
