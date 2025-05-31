#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int lenght = 0;
        int i = s.size() - 1;

        while (i >= 0 && s[i] == ' ') i--;

        while (i >= 0 && s[i] != ' ') {
            lenght++;
            i--;
        }

        return lenght;

}};

int main() {
    Solution sol;
    return 0;
}