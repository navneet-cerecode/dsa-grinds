#include <cctype>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool isPalindrome(const string& text) {
    int left = 0;
    int right = static_cast<int>(text.size()) - 1;

    while (left < right) {
        // Ignore punctuation and whitespace on either side.
        while (left < right &&
               !isalnum(static_cast<unsigned char>(text[left]))) {
            left++;
        }

        while (left < right &&
               !isalnum(static_cast<unsigned char>(text[right]))) {
            right--;
        }

        char leftCharacter =
            tolower(static_cast<unsigned char>(text[left]));
        char rightCharacter =
            tolower(static_cast<unsigned char>(text[right]));

        if (leftCharacter != rightCharacter) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {
    vector<pair<string, bool>> tests = {
        {"A man, a plan, a canal: Panama", true},
        {"race a car", false},
        {" ", true},
        {"0P", false},
        {".,", true},
        {"Madam", true},
        {"ab_a", true}
    };

    for (const auto& test : tests) {
        bool actual = isPalindrome(test.first);
        bool expected = test.second;

        cout << (actual ? "true" : "false")
             << " (expected " << (expected ? "true" : "false") << ")\n";
    }

    return 0;
}
