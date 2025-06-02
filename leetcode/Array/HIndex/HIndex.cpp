#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int lastIndex = citations.size()-1;
        int counter = 0;
        while(counter <= lastIndex){
            if(citations[lastIndex-counter] <= counter) return counter;
            counter++;
        }
        return counter;

    }
};

int main() {
    Solution sol;
    return 0;
}