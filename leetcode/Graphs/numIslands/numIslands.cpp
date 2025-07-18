#include <algorithm>  
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int countIsland = 0;
        int m = grid.size(), n = grid[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    countIsland++;
                }
            }
        }
        return countIsland;
    }

    void dfs(vector<vector<char>>&grid, int i, int j){
        if(i<0 || i>=grid.size() ||
           j<0 || j>=grid[0].size() ||
           grid[i][j] == '0'
        ) return;

        grid[i][j] = '0';

        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
};

int main() {
    return 0;
}