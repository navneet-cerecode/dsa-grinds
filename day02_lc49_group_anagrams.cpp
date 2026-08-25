#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(const vector<string>& words) {
    unordered_map<string, vector<string>> groups;

    // Every anagram produces the same key after its characters are sorted.
    for (const string& word : words) {
        string key = word;
        sort(key.begin(), key.end());
        groups[key].push_back(word);
    }

    vector<vector<string>> result;

    for (const auto& entry : groups) {
        result.push_back(entry.second);
    }

    return result;
}

vector<vector<string>> normalize(vector<vector<string>> groups) {
    for (vector<string>& group : groups) {
        sort(group.begin(), group.end());
    }
    sort(groups.begin(), groups.end());
    return groups;
}

int main() {
    vector<pair<vector<string>, vector<vector<string>>>> tests = {
        {
            {"eat", "tea", "tan", "ate", "nat", "bat"},
            {{"eat", "tea", "ate"}, {"tan", "nat"}, {"bat"}}
        },
        {{""}, {{""}}},
        {{"a"}, {{"a"}}},
        {{"ab", "ba", "abc", "cab", "bca"}, {{"ab", "ba"}, {"abc", "cab", "bca"}}},
        {{}, {}}
    };

    for (const auto& test : tests) {
        vector<vector<string>> actual = normalize(groupAnagrams(test.first));
        vector<vector<string>> expected = normalize(test.second);
        cout << (actual == expected ? "pass" : "fail") << '\n';
    }

    return 0;
}
