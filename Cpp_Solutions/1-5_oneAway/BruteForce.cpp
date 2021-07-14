// 1.5 One Away
// Brute Force

// Q: Given a string, write a funciton to check if it is a permutation of a palindrome.
// Assuming that str1 is the bigger/base string
#include <iostream>
#include <string>
#include <cstdlib>

// O(N)
bool oneAway(std::string str1, std::string str2) {
    if (std::abs(int(str1.length() - str2.length())) > 1) {
        return false;
    }
    int differentChar = 0;
    if (str1.length() == str2.length()) {
        for (int i = 0; i < str1.length(); ++i) {
            if (str1[i] != str2[i]) {
                if (differentChar == 1) {
                    return false;
                } else {
                    differentChar = 1;
                }
            }
        }
    } else {
        for (int i = 0; i < str2.length(); ++i) {
            if (str1[i+differentChar] != str2[i]) {
                if (differentChar == 1) {
                    return false;
                } else {
                    differentChar = 1;
                }
            }
        }
    }
    return true;
}

void tests() {
    // True tests
    assert(oneAway("pale", "ple"));
    assert(oneAway("pale", "pal"));
    assert(oneAway("pale", "gale"));
    assert(oneAway("pales", "pale"));
    assert(oneAway("pale", "pali"));
    assert(oneAway("a", ""));
    // False tests
    assert(!oneAway("pale", "salt"));
    assert(!oneAway("pale", "pa"));
    assert(!oneAway("pale", "paleee"));
    assert(!oneAway("pale", "lape"));
}

int main() {
    tests();
    return 0;
}