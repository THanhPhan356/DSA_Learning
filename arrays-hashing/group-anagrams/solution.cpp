#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> groups;

        for (const string& word : strs) {
            vector<int> key(26, 0);
            for (char c : word) {
                key[c - 'a']++;
            }
            groups[key].push_back(word);
        }

        vector<vector<string>> result;
        for (const auto& group : groups) {
            result.push_back(group.second);
        }
        return result;
    }
};
