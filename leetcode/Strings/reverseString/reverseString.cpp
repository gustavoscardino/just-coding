#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;
        while (start < end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
};

int main() {
    Solution sol;
    return 0;
}