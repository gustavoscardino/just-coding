#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};

// Testing
int main() {
    Solution sol;
    vector<int> digits = {1, 2, 3};
    digits = sol.plusOne(digits);
    printf("Result: ");
    for (int digit : digits) printf("%d ", digit);
    return 0;
}
