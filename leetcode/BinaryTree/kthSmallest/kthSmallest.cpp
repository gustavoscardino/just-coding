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
    int kthSmallest(TreeNode* root, int k) {
        int res = INT_MAX;
        int ini = 0;
        K_Smallest(root, k, ini, res);
        return res;
    }
    void K_Smallest(TreeNode* node, int n, int& k, int& res){
        if(!node) return;
        K_Smallest(node->left, n, k, res);
        k++;
        if(k==n)
            res = node->val;
        
        K_Smallest(node->right, n, k, res);
    }
};

int main() {
    return 0;
}