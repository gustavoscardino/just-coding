#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int line = 0;
        int column = 0;
        
        //check sub-boxes
        for (; line < 9; line += 3) {
            for (; column < 9; column += 3) {
                if (!checkSubBox(board, line, column)) return false;
            }
            column = 0;
        }

        //check lines
        for (int i = 0; i < 9; i++) {
            if (!checkLine(board, i)) return false;
        }

        //check columns
        for (int i = 0; i < 9; i++) {
            if (!checkColumn(board, i)) return false;
        }
        return true;
    }
    bool checkSubBox(vector<vector<char>>& board, int line, int column) {
        unordered_map<char, int> freq;
        for (int i = line; i < line + 3; i++) {
            for (int j = column; j < column + 3; j++) {
                if (board[i][j] != '.') {
                    freq[board[i][j]]++;
                    if (freq[board[i][j]] > 1) return false;
                }
            }
        }
        return true;
    }
    bool checkLine(vector<vector<char>>& board, int line) {
        unordered_map<char, int> freq;
        for (int i = 0; i < 9; i++) {
            if (board[line][i] != '.') {
                freq[board[line][i]]++;
                if (freq[board[line][i]] > 1) return false;
            }
        }
        return true;
    }
    bool checkColumn(vector<vector<char>>& board, int column) {
        unordered_map<char, int> freq;
        for (int i = 0; i < 9; i++) {
            if (board[i][column] != '.') {
                freq[board[i][column]]++;
                if (freq[board[i][column]] > 1) return false;
            }
        }
        return true;
    }
};

// Testing
int main() {
    Solution sol;
    // vector<int> nums = {0, 1, 0, 3, 12};
    // sol.twoSum(nums, 13);
    return 0;
}
