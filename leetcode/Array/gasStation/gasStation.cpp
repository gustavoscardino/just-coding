#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank = 0;
        int currTank = 0;
        int startStation = 0;

        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            totalTank += diff;
            currTank += diff;

            if (currTank < 0) {
                startStation = i + 1;
                currTank = 0;
            }
        }

        return totalTank >= 0 ? startStation : -1;
    }
};



int main() {
    Solution sol;
    return 0;
}