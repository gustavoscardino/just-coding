#include <algorithm>  
#include <queue>
#include <iostream>
#include <stack>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        bool inOrder = false;

        while(!q.empty()){
            int level = q.size();
            TreeNode* current;

            vector<int> thisLevel;
            for(int i=0; i<level; i++){
                current = q.front(); q.pop();
                thisLevel.push_back(current->val);
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            if(inOrder)
                reverse(thisLevel.begin(), thisLevel.end());
            inOrder = !inOrder;
            res.push_back(thisLevel);
        }
        return res;
    }
};

int main() {
    return 0;
}