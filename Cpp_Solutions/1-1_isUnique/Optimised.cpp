// 1.1 isUnique
// Optimised Solution

#include <iostream>
#include <string>

// ASSUMING str IS MADE UP OF ASCII characters (128)

bool isUnique(std::string str) {
   bool ascii_chars[128] = {false};
   for (int i = 0; i < str.length(); ++i) {
       if (ascii_chars[int(str[i])] == true) {
           return false;
       }
       ascii_chars[int(str[i])] = true;
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
