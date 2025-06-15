#include <algorithm>  
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;          
        if (!p || !q) return false;    
        if (p->val != q->val) return false; 

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


class Solution2 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> queue1, queue2;
        queue1.push(p);
        queue2.push(q);

        while (!queue1.empty() && !queue2.empty()) {
            TreeNode* node1 = queue1.front(); queue1.pop();
            TreeNode* node2 = queue2.front(); queue2.pop();

            if (!node1 && !node2) continue;
            if (!node1 || !node2) return false;
            if (node1->val != node2->val) return false;

            queue1.push(node1->left);
            queue1.push(node1->right);
            queue2.push(node2->left);
            queue2.push(node2->right);
        }

        return queue1.empty() && queue2.empty();
    }
};


int main() {

    return 0;
}