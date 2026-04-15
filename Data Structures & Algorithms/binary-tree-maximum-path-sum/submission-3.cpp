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
    int global_MAX = INT_MIN;
    int dfs(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int leftGain = max(0,dfs(root->left));
        int rightGain = max(0,dfs(root->right));

        int pathThroughRoot = root->val + leftGain + rightGain;

        global_MAX = max(global_MAX,pathThroughRoot);

        return root->val + max(leftGain , rightGain);
    }
    int maxPathSum(TreeNode* root) {
       dfs(root);
       return global_MAX;
    }
};
