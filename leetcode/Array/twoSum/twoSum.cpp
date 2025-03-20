#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numToIndex.find(complement) != numToIndex.end()) {
                result.push_back(numToIndex[complement]);
                result.push_back(i);
                return result;
            }
            numToIndex[nums[i]] = i;
        }
        return result;
    }
};

// Testing
int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};
    sol.twoSum(nums, 13);
    return 0;
}
