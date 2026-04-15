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
    int helper(TreeNode* root , int maxSoFar){
        int count =0;
        if(root==nullptr){
            return 0;
        }

        if (root->val >= maxSoFar) {
            count = 1;
            maxSoFar = root->val;   // update maxSoFar along this path
        }
        count += helper(root->left , maxSoFar);
        count += helper(root->right , maxSoFar);
        return count;
    }
    int goodNodes(TreeNode* root) {
        return helper(root,root->val);
    }
};
