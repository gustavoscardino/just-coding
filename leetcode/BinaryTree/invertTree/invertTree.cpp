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


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL || (root->right == NULL && root->left == NULL))
            return root;
        invert(root);
        return root;        
    }
    void invert(TreeNode* root){
        if(!root) return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invert(root->left);
        invert(root->right);
    }
};

int main() {
    return 0;
}