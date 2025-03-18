#include <iostream>
#include <vector>

#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicateHash(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.find(num) != seen.end()) return true;
            seen.insert(num);
        }
        return false;
    }
    bool containsDuplicateSort(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) return true;
        }

        return false;  
    }
};

int main(){
    return 0;
}