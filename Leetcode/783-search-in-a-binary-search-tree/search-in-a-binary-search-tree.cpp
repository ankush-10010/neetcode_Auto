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
    TreeNode* dfs(TreeNode* root,int val){
        if(root == nullptr) return nullptr;
        int curr_val = root->val;
        if(curr_val == val) return root;
        if(curr_val > val){
            // left
            return dfs(root->left,val);
        }else{
            //right
            return dfs(root->right,val);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) return nullptr;
        return dfs(root,val);
    }
};