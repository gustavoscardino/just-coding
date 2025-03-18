#include <iostream>
#include <vector>

#include <limits.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {    
            int temp = x % 10;
            
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && temp > 7)) return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && temp < -8)) return 0;
            
            res = res * 10 + temp; 
            x /= 10; 
        }
        return res;
    }
};

int main() {
    Solution sol;
    int x = 1534236469;
    x = sol.reverse(x);
    cout<<x;
    return 0;
}