// Casey Rose - CS310 - Module 6

#include <iostream>
#include <string>

// Simple function to check if a character is a vowel.
bool isVowel(char ch) {
    ch = std::tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

// Removes vowels from the input string and returns the result
std::string removeVowels(const std::string& input) {
    std::string output;
    for (char ch : input) {
        if (!isVowel(ch)) {
            output += ch;
        }
    }
    return output;
}

int main() {
    std::string userInput;

    std::cout << "Type something: ";
    std::getline(std::cin, userInput);

    std::string noVowels = removeVowels(userInput);

    std::cout << "Without vowels: " << noVowels << "\n";

    return 0;
}
