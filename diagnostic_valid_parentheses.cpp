#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool isValid(const string& s) {
    stack<char> brackets;

    for (char character : s) {
        // Opening brackets may need to be matched later.
        if (character == '(' || character == '{' || character == '[') {
            brackets.push(character);
            continue;
        }

        // A closing bracket cannot appear without an opening bracket.
        if (brackets.empty()) {
            return false;
        }

        char newest = brackets.top();
        bool mismatch =
            (character == ')' && newest != '(') ||
            (character == '}' && newest != '{') ||
            (character == ']' && newest != '[');

        if (mismatch) {
            return false;
        }

        brackets.pop();
    }

    // Every opening bracket must have been matched and removed.
    return brackets.empty();
}

int main() {
    vector<pair<string, bool>> tests = {
        {"()", true},
        {"()[]{}", true},
        {"(]", false},
        {"([{}])", true},
        {"([)]", false},
        {"]", false},
        {"((", false},
        {"", true}
    };

    for (const auto& test : tests) {
        const string& input = test.first;
        bool expected = test.second;
        bool actual = isValid(input);
        cout << '"' << input << "\" -> "
             << (actual ? "true" : "false")
             << " (expected " << (expected ? "true" : "false") << ")\n";
    }

    return 0;
}
