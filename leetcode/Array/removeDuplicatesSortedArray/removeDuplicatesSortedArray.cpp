#include <iostream>
#include <vector>

using std::vector;

class Solution {
    public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2;
        if (nums.size() <= 2) return nums.size();
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[k - 2]) { 
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,1,2,2,2,2,4,5,6};
    int k = sol.removeDuplicates(nums);
    printf("%d\n", k);
    std::cout << "End";
}