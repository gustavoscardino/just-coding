#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

class Solution{
public:
    void removeNode(ListNode* node){
        node->val = (node->next)->val;
        node->next = (node->next)->next;
    }
};

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Original List: ";
    printList(head);

    ListNode* nodeToDelete = head->next;  

    Solution sol;
    sol.removeNode(nodeToDelete);

    cout << "List after deleting node 5: ";
    printList(head);

    return 0;
}