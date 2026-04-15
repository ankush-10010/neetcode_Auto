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
    vector<int> result_vec(TreeNode *root, vector<int> &result){
        if(root==nullptr){
            return result;
        }
        result_vec(root->left , result);
        result_vec(root->right , result);
        result.push_back(root->val);
        return result;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        result = result_vec(root,result);
        sort(result.begin(), result.end());
        return result[k-1];
    }
};
