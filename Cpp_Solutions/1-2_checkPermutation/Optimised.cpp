// 1.2 checkPermutation
// Optimised

// Q: Given two strings, decide if one is a permuation of the other.

#include <iostream>
#include <string>
#include <unordered_map>

// O(N^2)
bool checkPermuation(std::string str1, std::string str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    
    std::unordered_map<std::string, int> map = {};
    for (int i = 0; i < str1.length(); ++i) {
        if (map.find(std::string(str1[i],1)) != map.end()) {
            map[std::string(str1[i],1)] = map[std::string(str1[i],1)] + 1;
        } else {
            map[std::string(str1[i],1)] = 1;
        }
    }
    for (int i = 0; i < str2.length(); ++i) {
        if (map.find(std::string(str2[i],1)) != map.end()) {
            if (map[std::string(str2[i],1)] > 0) {
                map[std::string(str2[i],1)] = map[std::string(str2[i],1)] - 1;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

void tests() {
    std::string str1[10] = {"sean", "mississippi", "a", "", "bbbbb", "abcdefghijk123456789/(=)", "abcde", "aa", "abc", "hello"};
    std::string str2[10] = {"naes", "simsissppii", "a", "", "bbbbb", "123459876/()=abcdefghijk", "abcd", "a", "bacc", "helllo"};
    
    for (int i = 0; i < 10; ++i) {
        if (i < 6) {
            assert(checkPermuation(str1[i], str2[i]));
        } else {
            assert(!(checkPermuation(str1[i], str2[i])));
        }
    }
}

int main() {
    tests();
    return 0;
}
