// 1.1 isUnique
// Brute Force

#include <iostream>
#include <string>

bool isUnique(std::string str) {
    for (int i = 0; i < str.length(); ++i) {
        for (int x = 0; x < str.length(); ++x) {  
            if (x != i) {
                if (str[i] == str[x]) {
                    return false;
                }
            }
        }
    }
    return true;
}

void tests() {
    std::string unique[5] = {"", "a", "abcdefghijklmnopqrstuvwxyz1234567890!$%&()=?#+*", "seandvi", "A65"};
    std::string not_unique[6] = {"  ", "aa", "mississippi", "abcdefghijklmnoa", "abc$lmno$p", "abcd,,efghijk"};
    
    for (const std::string &str : unique) {
        assert(isUnique(str));
    }
    for (const std::string &str : not_unique) {
        assert(!(isUnique(str)));
    }
}

int main() {
    tests();    
    return 0;
}
