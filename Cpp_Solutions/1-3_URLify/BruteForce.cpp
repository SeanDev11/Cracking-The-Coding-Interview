// 1.3 URLify
// Brute Force

// Q: Write a method to replace all spaces in a string with '%20'.

#include <iostream>
#include <string>

// O(N)
void URLify(std::string str, int true_length) {
    int spaces = (str.length() - true_length)/2;
    for (int i = true_length-1; i > -1; --i) {
        if (str[i] != ' ') {
            str[i+(spaces*2)] = str[i];
            str[i] = ' ';
        } else {
            str[i+(spaces*2)] = '0';
            str[i+(spaces*2)-1] = '2';
            str[i+(spaces*2)-2] = '%';
            spaces = spaces - 1;
        }
        if (spaces == 0) {
            break;
        }
    }
    std::cout << str << std::endl;
}

void tests() {
    URLify("Mr John Smith    ", 13);
    URLify("Eintracht  Frankfurt    ", 20);
    URLify(" Hello There    ", 12);
    URLify("   ", 1);
}

int main() {
    tests();
    return 0;
}