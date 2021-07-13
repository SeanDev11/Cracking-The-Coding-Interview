// 1.4 Palindrome Permutation
// Optimised

// Q: Given a string, write a funciton to check if it is a permutation of a palindrome.
// Can ignore casing and non-letter characters.
// Assuming ASCII chars only
#include <iostream>
#include <string>

// O(N)
bool palindromePermutation(std::string str) {
    int charCount[128] = {0};
    int oddCount = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != ' ') {
            charCount[int(tolower(str[i]))]++;
            if (charCount[int(tolower(str[i]))] % 2 != 0) {
                oddCount++;
            } else {
                oddCount--;
            }
        }
    }
    return oddCount <= 1; 
}

void tests() {
    bool t = palindromePermutation("Tact coooa");
    std::cout << t << std::endl;
}

int main() {
    tests();
    return 0;
}