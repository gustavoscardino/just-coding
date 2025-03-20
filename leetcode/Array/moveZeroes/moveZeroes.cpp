#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0;
        int end = nums.size();
        while (start < end){
            if (nums[start] == 0){
                nums.erase(nums.begin() + start);
                nums.push_back(0);
                end--;
            } else {
                start++;
            }
        }
    }
};

// Testing
int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums);
    return 0;
}
