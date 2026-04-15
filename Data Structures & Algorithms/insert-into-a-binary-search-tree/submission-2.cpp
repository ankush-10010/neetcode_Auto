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
    TreeNode* dfs(TreeNode* curr,int val){
        if(curr == nullptr){
            TreeNode* newCurr = new TreeNode(val);
            curr = newCurr;
            return curr;
        }
        if(val > curr->val){
            curr->right = dfs(curr->right,val);
        }
        if(val < curr->val){
            curr->left = dfs(curr->left,val);
        }
        return curr;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //iterate such that we reach the node where it can be added
        // base case --> 
        // if curr->val>value given , iterate back and see the root or root->left
        // if curr->val<val                                            root->right
        root = dfs(root,val);
        return root;
    }
};