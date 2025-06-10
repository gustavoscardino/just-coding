#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        unordered_set<int> set;
        int maxLen = 0;

        for (int n:nums) 
            set.insert(n);

        int currLen = 1;
        for (int n:set){
            if (set.find(n-1) == set.end()){
                currLen = 1;
                int n1 = n;
                while (set.find(n1+1) != set.end()){
                    currLen++;
                    n1++;
                }
                maxLen = max (maxLen, currLen);
            }
        }

        return maxLen;
    }
};

int main() {
    Solution sol;
    return 0;
}