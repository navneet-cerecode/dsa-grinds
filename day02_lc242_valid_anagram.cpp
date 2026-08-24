#include <array>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool isAnagram(const string& s, const string& t) {
    if (s.length() != t.length()) {
        return false;
    }

    array<int, 26> frequency{};

    // Add characters from s and cancel them using characters from t.
    for (char character : s) {
        frequency[character - 'a']++;
    }

    for (char character : t) {
        frequency[character - 'a']--;
    }

    for (int count : frequency) {
        if (count != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<pair<pair<string, string>, bool>> tests = {
        {{"anagram", "nagaram"}, true},
        {{"rat", "car"}, false},
        {{"aacc", "ccac"}, false},
        {{"abb", "bab"}, true},
        {{"a", "ab"}, false},
        {{"", ""}, true}
    };

    for (const auto& test : tests) {
        const string& s = test.first.first;
        const string& t = test.first.second;
        bool expected = test.second;
        bool actual = isAnagram(s, t);

        cout << (actual ? "true" : "false")
             << " (expected " << (expected ? "true" : "false") << ")\n";
    }

    return 0;
}
