#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};


        vector<string> res;
        int pos1=0, pos2=1;

        for (; pos2<=nums.size(); pos2++){
            if (pos2 == nums.size() || nums[pos2] != nums[pos2-1] + 1) {
                if (pos1 == pos2 - 1) {
                    res.push_back(to_string(nums[pos1]));
                } else {
                    res.push_back(to_string(nums[pos1]) + "->" + to_string(nums[pos2-1]));
                }
                pos1 = pos2;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}