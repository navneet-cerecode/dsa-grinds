#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

vector<int> twoSumRevision(const vector<int>& nums, int target) {
    unordered_map<int, int> seen;

    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        int complement = target - nums[i];

        // The map stores each previously visited number and its index.
        if (seen.find(complement) != seen.end()) {
            return {seen[complement], i};
        }

        // Insert after lookup so the current element cannot match itself.
        seen[nums[i]] = i;
    }

    return {};
}

void printVector(const vector<int>& nums) {
    cout << '[';
    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        if (i > 0) {
            cout << ", ";
        }
        cout << nums[i];
    }
    cout << ']';
}

bool isValidAnswer(const vector<int>& nums, int target, const vector<int>& answer) {
    if (answer.size() != 2) {
        return false;
    }

    int first = answer[0];
    int second = answer[1];
    int n = static_cast<int>(nums.size());

    return first >= 0 && first < n && second >= 0 && second < n &&
           first != second && nums[first] + nums[second] == target;
}

int main() {
    vector<pair<vector<int>, int>> tests = {
        {{2, 7, 11, 15}, 9},
        {{3, 2, 4}, 6},
        {{3, 3}, 6},
        {{-3, 4, 3, 90}, 0},
        {{0, 4, 3, 0}, 0}
    };

    for (const auto& test : tests) {
        const vector<int>& nums = test.first;
        int target = test.second;
        vector<int> answer = twoSumRevision(nums, target);

        printVector(answer);
        cout << " -> " << (isValidAnswer(nums, target, answer) ? "valid" : "invalid")
             << '\n';
    }

    return 0;
}
