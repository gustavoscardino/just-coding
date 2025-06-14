#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> res;
        for (char c: s){

            switch (c)
            {
            case ')':
                if(res.top() != '(') return false;
                res.pop();
            break;
            
            case ']':
                if(res.top() != '[') return false;
                res.pop();
            break;
            
            case '}':
                if(res.top() != '{') return false;
                res.pop();
            break;

            default:
                res.push(c);
                break;
            }
        }
        return res.empty();
    }
};

int main() {
    Solution sol;
    return 0;
}