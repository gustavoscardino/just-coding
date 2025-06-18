#include <algorithm>  
#include <queue>
#include <iostream>
#include <cmath>
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
    void flatten(TreeNode* root) {
        if(!root) return;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* current = q.front(); q.pop();

            insert(current->right, current->left);
            if(current->left){
                current->right = current->left;
                current->left = NULL;
            }
            

            if(current->right) q.push(current->right);
        }
        
    }
    void insert(TreeNode* right, TreeNode* left){
        while(right && left){
            if(left->right) left = left->right;
            else {
                left->right = right;
                return;
            }
        }
    }
};

class Solution2 {
public:
    void flatten(TreeNode* root) {
        if(!root) return;

        TreeNode* tempRight = root->right;
        root->right = root->left;
        root->left = nullptr;

        TreeNode* current = root;
        while (current->right) {
            current = current->right;
        }
        current->right = tempRight;
        flatten(root->right);
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(6);

    sol.flatten(root);
    return 0;
}