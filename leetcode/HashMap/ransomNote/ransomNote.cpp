#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> count;
        for (char c: magazine)
            count[c]++;
        for(char c: ransomNote){
            if(count[c]<=0) return false;
            count[c]--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    return 0;
}