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
    void dfs(TreeNode* root,vector<int>& r1){
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            r1.push_back(root->val);
        }
        dfs(root->left,r1);
        dfs(root->right,r1);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1;
        vector<int> r2;
        dfs(root1,r1);
        dfs(root2,r2);

        // sort(r1.begin(),r1.end());
        // sort(r2.begin(),r2.end());

        if(r1.size() != r2.size()) return false;
        for(int i=0;i<r1.size();i++){
            if(r1[i] != r2[i]) return false;
        }
        return true;
    }
};