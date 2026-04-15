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
    TreeNode* dfs(TreeNode* root,int target){
        if(root == nullptr){
            return root;
        }
        
        //think in terms of postorder traversal (left,right,node)
        //we send our recursive function all the way down the left subtree to do its job
        // we send out recursive funtion all the way down the right subtree to do its job
        // only then do we look at the current parent node
        
        root->left = dfs(root->left,target);
        root->right = dfs(root->right,target);
        if(root->val == target){
            if(root->right == nullptr && root->left == nullptr){
                delete root;
                return nullptr;
            }
        }
        return root;

    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* output = dfs(root,target);
        return output;
    }
};