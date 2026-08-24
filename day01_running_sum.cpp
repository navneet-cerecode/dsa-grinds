#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<int> runningSum(vector<int>& nums) {
    int currentSum = 0;

    // Store each prefix sum directly in the input array.
    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        currentSum += nums[i];
        nums[i] = currentSum;
    }

    return nums;
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

int main() {
    vector<pair<vector<int>, vector<int>>> tests = {
        {{1, 2, 3, 4}, {1, 3, 6, 10}},
        {{1, 1, 1, 1, 1}, {1, 2, 3, 4, 5}},
        {{3, 1, 2, 10, 1}, {3, 4, 6, 16, 17}},
        {{5}, {5}},
        {{1, -1, 2, -2}, {1, 0, 2, 0}},
        {{}, {}}
    };

    for (const auto& test : tests) {
        vector<int> actual = test.first;
        const vector<int>& expected = test.second;
        vector<int> returned = runningSum(actual);

        printVector(returned);
        cout << " (expected ";
        printVector(expected);
        cout << ")\n";
    }

    return 0;
}
