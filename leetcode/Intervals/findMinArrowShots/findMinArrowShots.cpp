#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution2 {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int arrows = 1;
        int lastArrowPos = points[0][1];
        
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > lastArrowPos) {
                arrows++;
                lastArrowPos = points[i][1];
            }
        }
        
        return arrows;
    }
}; 
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        sort(points.begin(), points.end());
        
        int arrows = 0;
        int i = 0;
        
        while (i < points.size()) {
            int end = points[i][1];
            int start = i;
            
            while (i < points.size() && points[i][0] <= end) {
                end = min(end, points[i][1]); 
                i++;
            }
            
            arrows++;
        }
        
        return arrows;
    }
};


int main() {
    Solution sol;
    vector<vector<int>>vec={{1,2},{2,3},{3,4},{4,5}};

    sol.findMinArrowShots(vec);

    return 0;
}