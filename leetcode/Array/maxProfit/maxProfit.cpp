#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price; 
            } else {
                maxProfit = max(maxProfit, price - minPrice);  
            }
        }
        return maxProfit;
    }
    };

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    Solution sol;
    cout << "Max Profit: " << sol.maxProfit(prices) << endl;
    return 0;
}