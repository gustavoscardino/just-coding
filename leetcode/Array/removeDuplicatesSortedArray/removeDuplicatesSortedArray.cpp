#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int p1 = 0;
        int p2 = 0;
        while(p2 < nums.size()){
            if (nums[p2] != nums[p1]){
                nums[p1 + 1] = nums [p2];
                p1++;
            }
            else p2++;
        }
        return p1 + 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int k = sol.removeDuplicates(nums);
    printf("%d\n", k);
    // print nums   
    for (int i = 0; i < k; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << "End";
}