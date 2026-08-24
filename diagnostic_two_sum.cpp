#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    // Maps each previously visited number to its index.
    unordered_map<int, int> seen;

    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        // The current number needs this value to reach the target.
        int complement = target - nums[i];

        // Check first so the current element cannot match with itself.
        if (seen.find(complement) != seen.end()) {
            return {seen[complement], i};
        }

        seen[nums[i]] = i;
    }

    // The problem guarantees an answer, so this is only a safe fallback.
    return {};
}

int main() {
    vector<int> nums = {3, 2, 4};
    int target = 6;

    vector<int> answer = twoSum(nums, target);

    if (answer.size() == 2) {
        cout << answer[0] << " " << answer[1] << '\n';
    } else {
        cout << "No answer returned\n";
    }

    return 0;
}
