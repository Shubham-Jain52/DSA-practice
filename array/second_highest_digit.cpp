// This program finds the second highest digit in a string.

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

// The class structure you provided
class Solution {
public:
    int secondHighest(std::string s) {
        std::vector<int> digits;
        // Loop 1: Find all digits and store their integer values.
        // This is the corrected version of your first loop.
        for (char c : s) {
            if (isdigit(c)) {
                // Convert char '0'-'9' to int 0-9 and add to vector
                digits.push_back(c - '0');
            }
        }

        // Initialize largest and second-highest to -1.
        // -1 indicates "not found yet".
        int largest = -1;
        int shighest = -1;

        // Loop 2: Find the largest and second-largest unique digit.
        // This is the corrected version of your second loop.
        for (int digit : digits) {
            if (digit > largest) {
                shighest = largest; // Old largest becomes new second-highest
                largest = digit;    // New digit is now the largest
            } else if (digit > shighest && digit < largest) {
                // A new second-highest is found
                shighest = digit;
            }
        }

        // shighest will remain -1 if no second-highest digit was found.
        return shighest;
    }
};

// Main function to test the code
int main() {
    Solution sol;
    std::string s1 = "dfa12321afd";
    std::string s2 = "abc1111";
    std::string s3 = "abc";
    std::string s4 = "xyz98759";

    std::cout << "Input: \"" << s1 << "\" -> Second highest: " << sol.secondHighest(s1) << std::endl;
    std::cout << "Input: \"" << s2 << "\" -> Second highest: " << sol.secondHighest(s2) << std::endl;
    std::cout << "Input: \"" << s3 << "\" -> Second highest: " << sol.secondHighest(s3) << std::endl;
    std::cout << "Input: \"" << s4 << "\" -> Second highest: " << sol.secondHighest(s4) << std::endl;

    return 0;
}
