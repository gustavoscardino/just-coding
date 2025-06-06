#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxA = (right-left)*max(height[left], height[right]);
        while(left<right){
            if (height[left] < height[right]){
                left++;
                if (height[left] > height[left-1])
                    maxA = max(maxA, (right-left)*max(height[left], height[right]));
            }
            else{
                right--;
                if (height[right] > height[left+1])
                    maxA = max(maxA, (right-left)*max(height[left], height[right]));
            }

        }
        return maxA;
    }
};

int main() {
    Solution sol;
    return 0;
}
