#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp = head;

        while (temp) {
            length++;
            temp = temp->next;
        }

        int removePos = length - n;
        temp = head;

        if (removePos == 0) return head->next;

        for (int i = 0; i < removePos - 1; i++) {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }

    ListNode* removeNthFromEndOnePass(ListNode* head, int n) {
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* fast = temp;
        ListNode* slow = temp;

        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return temp->next;
    }
};

int main() {


    return 0;
}