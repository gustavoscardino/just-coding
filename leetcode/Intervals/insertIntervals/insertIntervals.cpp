#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert1(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return vector<vector<int>>{newInterval};
        
        vector<vector<int>> res;
        bool inserted = false;
        for (int i=0; i<intervals.size(); i++){
            if(intervals[i][0] < newInterval[0] || inserted)
                res.push_back(intervals[i]);
            else{
                res.push_back(newInterval);
                inserted = true;
                res.push_back(intervals[i]);
            }
        }
        if(!inserted) res.push_back(newInterval);

        //merge res
        intervals.clear();
        int start = res[0][0];
        int end = res[0][1];
        for(int i=1; i<res.size(); i++){
            if(end < res[i][0]){
                intervals.push_back(vector<int>{start,end});
                start = res[i][0];
                end = res[i][1];
            }
            else{
                end = max(end, res[i][1]);
            }
        }
   
        intervals.push_back(vector<int>{start,end});
        return intervals;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();
        
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);
        
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};  


int main() {
    Solution sol;
    return 0;
}