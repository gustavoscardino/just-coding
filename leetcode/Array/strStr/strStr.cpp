#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hSize = haystack.size();
        int nSize = needle.size();

        if (nSize == 0) return 0;
        if (nSize > hSize) return -1;

        for (int i = 0; i <= hSize - nSize; i++) {
            if (haystack.substr(i, nSize) == needle) {
                return i;
            }
        }
        return -1;

        // size_t pos = haystack.find(needle);
        // return (pos != string::npos) ? pos : -1;
        
    }
};

int main() {
    Solution sol;
    return 0;
}