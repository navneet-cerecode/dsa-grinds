#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool isValidParentheses(const string& text) {
    stack<char> brackets;

    for (char character : text) {
        if (character == '(' || character == '{' || character == '[') {
            brackets.push(character);
            continue;
        }

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
        {"(((", false},
        {"", true}
    };

    for (const auto& test : tests) {
        bool actual = isValidParentheses(test.first);
        bool expected = test.second;

        cout << (actual ? "true" : "false")
             << " (expected " << (expected ? "true" : "false") << ")\n";
    }

    return 0;
}
