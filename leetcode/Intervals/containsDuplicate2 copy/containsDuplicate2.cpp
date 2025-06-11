#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mapIndex;

        for (int i=0; i< nums.size(); i++){
            if(mapIndex.find(nums[i])==mapIndex.end())
                mapIndex[nums[i]] = i;
            else
                if(i-mapIndex[nums[i]] <= k)    
                    return true;
                else
                    mapIndex[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    Solution sol;
    return 0;
}