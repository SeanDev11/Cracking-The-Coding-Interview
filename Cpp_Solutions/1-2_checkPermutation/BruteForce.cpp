// 1.2 checkPermutation
// Brute Force

// Q: Given two strings, decide if one is a permuation of the other.

#include <iostream>
#include <string>

// O(N^2)
bool checkPermuation(std::string str1, std::string str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    for (int i = 0; i < str1.length(); ++i) {
        bool found = false;
        for (int x = 0; x < str2.length(); ++x)
            if (str1[i] == str2[x]) {
                str2[x] = "";
                found = true;
            }
            if (!found) {
                return false;
            }
    }
    return true;
}

void tests() {
    std::string str1[5] = {"", "a", "abcdefghijklmnopqrstuvwxyz1234567890!$%&()=?#+*", "seandvi", "A65"};
    std::string str2[5] = {"aa", "mississippi", "abcdefghijklmnoa", "abc$lmno$p", "abcd,,efghijk"};
    
    for (int i = 0; i < str1.size(); ++i) {
        if (i < 5) {
            assert(checkPermuation(str1[i], str2[i]))
        } else {
            assert(!(checkPermuation(str1[i], str2[i])))
        }
    }
}

int main() {
    tests();
    return 0;
}
