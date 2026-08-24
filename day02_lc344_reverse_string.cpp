#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void reverseString(vector<char>& characters) {
    int left = 0;
    int right = static_cast<int>(characters.size()) - 1;

    // Swap matching outer positions, then move toward the center.
    while (left < right) {
        swap(characters[left], characters[right]);
        left++;
        right--;
    }
}

void printCharacters(const vector<char>& characters) {
    cout << '[';
    for (int i = 0; i < static_cast<int>(characters.size()); i++) {
        if (i > 0) {
            cout << ", ";
        }
        cout << '\'' << characters[i] << '\'';
    }
    cout << ']';
}

int main() {
    vector<pair<vector<char>, vector<char>>> tests = {
        {{'h', 'e', 'l', 'l', 'o'}, {'o', 'l', 'l', 'e', 'h'}},
        {{'H', 'a', 'n', 'n', 'a', 'h'}, {'h', 'a', 'n', 'n', 'a', 'H'}},
        {{'a'}, {'a'}},
        {{'a', 'b'}, {'b', 'a'}},
        {{}, {}}
    };

    for (const auto& test : tests) {
        vector<char> actual = test.first;
        const vector<char>& expected = test.second;
        reverseString(actual);

        printCharacters(actual);
        cout << " (expected ";
        printCharacters(expected);
        cout << ")\n";
    }

    return 0;
}
