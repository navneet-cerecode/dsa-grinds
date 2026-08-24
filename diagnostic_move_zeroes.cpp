#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    int write = 0;

    // Copy non-zero values forward while preserving their order.
    for (int read = 0; read < n; read++) {
        if (nums[read] != 0) {
            nums[write] = nums[read];
            write++;
        }
    }

    // Every position after the last non-zero value becomes zero.
    for (int i = write; i < n; i++) {
        nums[i] = 0;
    }
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
        {{0, 1, 0, 3, 12}, {1, 3, 12, 0, 0}},
        {{0}, {0}},
        {{1, 2, 3}, {1, 2, 3}},
        {{0, 0, 1}, {1, 0, 0}},
        {{1, 0, 2, 0, 3}, {1, 2, 3, 0, 0}},
        {{}, {}}
    };

    for (const auto& test : tests) {
        vector<int> actual = test.first;
        const vector<int>& expected = test.second;
        moveZeroes(actual);

        printVector(actual);
        cout << " (expected ";
        printVector(expected);
        cout << ")\n";
    }

    return 0;
}
