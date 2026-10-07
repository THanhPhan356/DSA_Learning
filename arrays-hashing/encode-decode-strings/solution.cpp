#include <cstddef>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        for (const string& s : strs) {
            res.append(to_string(s.size()));
            res.push_back('@');
            res.append(s);
        }
        return res;
    }

    // Input must have been produced by encode().
    vector<string> decode(string s) {
        vector<string> res;
        size_t i = 0;

        while (i < s.size()) {
            size_t j = i;
            // Read all digits of the length up to the separator.
            while (s[j] != '@') {
                ++j;
            }

            size_t length = stoul(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, length));
            i = j + 1 + length;
        }
        return res;
    }
};
