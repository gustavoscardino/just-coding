
#include <algorithm>  
#include <queue>
#include <iostream>
#include <stack>
#include <climits>
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool isValid = true;
        TreeNode* prev = NULL;
        checkValidBST(root, prev, isValid);
        return isValid;
    }   

    void checkValidBST(TreeNode* node,TreeNode*& prev, bool& isValid ){
        if(!node) return;
        checkValidBST(node->left, prev, isValid);
        if(prev && prev->val >= node->val)
            isValid = false;
        prev = node;
        checkValidBST(node->right, prev, isValid);
    }
};

int main() {
    return 0;
}