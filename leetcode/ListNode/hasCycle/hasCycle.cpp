#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        while(head != NULL){
            if(set.find(head) != set.end())
                return true;
            set.insert(head);
            head = head->next;
        }
        return false;
    }
};

int main() {

    return 0;
}