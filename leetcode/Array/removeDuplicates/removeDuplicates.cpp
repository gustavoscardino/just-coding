#include <iostream>
#include <vector>

using std::vector;

class Solution {
    public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
    
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) { 
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