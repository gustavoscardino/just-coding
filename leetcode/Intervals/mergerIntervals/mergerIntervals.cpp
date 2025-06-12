#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return intervals;
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        vector<vector<int>> res;
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            } else {
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        res.push_back({start, end});
        
        return res;
    }
};

int main() {
    Solution sol;
    return 0;
}