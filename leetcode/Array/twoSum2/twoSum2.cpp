#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int pos1 = 0;
        int pos2 = numbers.size()-1;

        while (pos1<pos2){
            int t = numbers[pos1] + numbers[pos2];
            if (t == target) return vector<int>{pos1+1,pos2+1};
            else if (t>target) pos2--;
            else pos1++; 
        }   
        return vector<int>{pos1+1,pos2+1};
    }
};

int main() {
    Solution sol;
    return 0;
}