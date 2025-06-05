#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pnt1 = 0;
        int pnt2 = 0;
        while (pnt2 < t.size() && pnt1 < s.size()){
            if (s[pnt1] == t[pnt2]){
                pnt1++;
            }
            pnt2++;
        }
        return pnt1 >= s.size();
    }
};

int main() {
    Solution sol;
    return 0;
}