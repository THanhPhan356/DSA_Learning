#include <cctype>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        std::string s1;

        for (unsigned char c : s) {
            if (std::isalnum(c)) {
                s1 += static_cast<char>(std::tolower(c));
            }
        }

        int start = 0;
        int end = static_cast<int>(s1.size()) - 1;

        while (start < end) {
            if (s1[start] != s1[end]) {
                return false;
            }

            ++start;
            --end;
        }

        return true;
    }
};
