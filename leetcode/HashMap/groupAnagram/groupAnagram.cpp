#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (const string& s : strs) {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());
            map[sortedStr].push_back(s);
        }

        vector<vector<string>> res;
        for (const auto& pair: map){
            res.push_back(pair.second);
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}