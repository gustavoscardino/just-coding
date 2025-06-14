#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

class MinStack {
private:
    stack<int> dataStack;
    stack<int> minStack;

public:
    MinStack() {
    }
    
    void push(int val) {
        dataStack.push(val);
        
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (dataStack.top() == minStack.top()) {
            minStack.pop();
        }
        dataStack.pop();
    }
    
    int top() {
        return dataStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


int main() {

    return 0;
}