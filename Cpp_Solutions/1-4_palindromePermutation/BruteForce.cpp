// 1.4 Palindrome Permutation
// Brute Force

// Q: Given a string, write a funciton to check if it is a permutation of a palindrome.
// Can ignore casing and non-letter characters.
// Assuming ASCII chars only
#include <iostream>
#include <string>

// O(N)
bool palindromePermutation(std::string str) {
    int charCount[128] = {0};
    bool oddCharCount = false;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != ' ') {
            charCount[int(tolower(str[i]))]++;
        }
    }

    for (int i = 0; i < 128; ++i) {
        
        if (charCount[i] % 2 != 0) {
            if (oddCharCount) {
                return false;
            } else {
                oddCharCount = true;
            } 
        }
        
    }
    return true; 
}

void tests() {
    bool t = palindromePermutation("Tact coa");
    std::cout << t << std::endl;
}

int main() {
    tests();
    return 0;
}