#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map ={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int value = 0;
        for (int i=0; i<s.size(); i++){
            if (map[s[i+1]]>map[s[i]]){
                value += map[s[i+1]]-map[s[i]];
                i++;
            }
            else value += map[s[i]];
        }   
        return value;
    }
};



int main() {
    Solution sol;
    return 0;
}