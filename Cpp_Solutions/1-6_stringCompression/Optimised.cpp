// 1.6 String Compression
// Optimised

// Q: Implement basic string compression using the counts of repeated characters. For example, aabcccccaaa
// would become a2b1c5a3. If the "compressed" string would not become smaller than the original string, your
// method should return the original string.
// Assuming the string has only upper and lowercase letters (a-z)
#include <iostream>
#include <string>
#include <cstdlib>

// O(N)
std::string stringCompression(std::string toCompress) {
    if (toCompress.length() < 3) {
        return toCompress;
    }
    std::string compressed = "";
    char lastChar = toCompress[0];
    int lastCharCount = 1;
    for (int i = 1; i < toCompress.length(); ++i) {
        if (lastChar != toCompress[i]) {
            compressed.append((std::string(1, lastChar).append(std::to_string(lastCharCount))));
            lastCharCount = 1;
            lastChar = toCompress[i];
        } else {
            lastCharCount++;
        }
    }
    compressed.append((std::string(1, lastChar).append(std::to_string(lastCharCount))));
    if (compressed.length() < toCompress.length()) {
        return compressed;
    } else {
        return toCompress;
    }
}

void tests() {
    std::cout << stringCompression("aabcccccaaa") << std::endl;
    std::cout << stringCompression("aabcccccaaat") << std::endl;
    std::cout << stringCompression("abcdefghijkl") << std::endl;    
    std::cout << stringCompression("") << std::endl;
    std::cout << stringCompression("a") << std::endl;
    std::cout << stringCompression("aa") << std::endl;
    std::cout << stringCompression("aaa") << std::endl;
    std::cout << stringCompression("abbbbbbbbbcop") << std::endl;
    std::cout << stringCompression("AaaaaaBBb") << std::endl;
}

int main() {
    tests();
    return 0;
}