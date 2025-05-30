#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
       // sort nums
       sort(nums.begin(), nums.end());
       return nums[nums.size() / 2];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,0,0,1,1,1,1,1,2,2,2};
    int k = sol.majorityElement(nums);
    printf("%d\n", k);
}