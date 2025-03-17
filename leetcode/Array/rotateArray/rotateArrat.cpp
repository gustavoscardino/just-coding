#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            // vector<int> rot(nums.size());
            // int size = nums.size();
            // if (size < 2) return; 
            // for (int i = 0; i < size; i++){
            //     rot[(i+k)%size] = nums[i];
            // }
            // nums = rot;
            k = k % nums.size();
            reverse(nums, 0, nums.size()-1);
            reverse(nums, 0, k-1);
            reverse(nums, k, nums.size()-1);
        }
    private:
        void reverse(vector<int>&nums, int start, int end){
            while(start<end) swap(nums[start++], nums[end--]);
        }
    };


int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    Solution sol;
    sol.rotate(nums, k);
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", "; 
    }
    return 0;
}