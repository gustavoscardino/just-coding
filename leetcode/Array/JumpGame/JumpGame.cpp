#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int untilZero(vector<int>& nums, int start){
        int i = start;
        for (; i < nums.size(); i++){
            if (nums[i] == 0) return i;
        }
        return i;
    }
    bool canJump(vector<int>& nums) {

        int start = 0;
        int zeroIndex = -1;

        while(true){
            zeroIndex = untilZero(nums, start);
            if (zeroIndex >= nums.size() -1) return true;
            bool jumped = false;
            for (int j = 1; j <= zeroIndex; j++){
                if (nums[zeroIndex-j] > j) { jumped = true; break;};
            }
            if (jumped) start = zeroIndex+1;
            else return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    return 0;
}