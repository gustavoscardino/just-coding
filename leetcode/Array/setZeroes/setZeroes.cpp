#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); //rows
        int n = matrix[0].size(); //columns
        unordered_set<int> setRows;
        unordered_set<int> setColumns;

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++) 
                if(matrix[i][j]==0) {
                    setRows.insert(i);
                    setColumns.insert(j);
                }
        }
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++) {
                if(setRows.find(i)!=setRows.end()) matrix[i][j]=0;
                else if(setColumns.find(j)!=setColumns.end()) matrix[i][j]=0;
            }
        }
    }
};


int main() {
    Solution sol;

 
    return 0;
}