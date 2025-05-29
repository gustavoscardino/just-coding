#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
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
    int val = 2; 
    int k = sol.removeElement(nums, val);
    printf("%d\n", k);
    std::cout << "End";
}