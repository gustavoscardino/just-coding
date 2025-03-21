#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int firstUniqChar(string s) {
            for (char c : s) {
                if (s.find(c) == s.rfind(c)) return s.find(c);
            }
            return -1;
        }
        int firstUniqChar2(string s) {
            unordered_map<char, int> freq;
            for (char c : s) {
                freq[c]++;
            }  
            for (int i = 0; i < s.size(); i++) {
                if (freq[s[i]] == 1) return i;
            }
            return -1;
        }
    };

int main() {
    Solution sol;

    return 0;
}