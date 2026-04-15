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
    pair<int,int> dfs(TreeNode* root){
        if(root == nullptr){
            return {0,0};
        }
        pair<int,int> recursive_output;
        pair<int,int> left_choices = dfs(root->left);
        pair<int,int> right_choices = dfs(root->right);
        recursive_output.first= root->val + left_choices.second + right_choices.second;
        recursive_output.second = max(left_choices.first, left_choices.second) + 
                        max(right_choices.first, right_choices.second);
        
        return recursive_output;
    }
    int rob(TreeNode* root) {
        // unordered_map<TreeNode*,int> rob_current_max;
        // unordered_map<TreeNode*,int> dont_rob_current_max;

        pair<int,int>result=dfs(root);
        //p.first --> rob , p.second-->not rob
        return max(result.first,result.second);
    }
};