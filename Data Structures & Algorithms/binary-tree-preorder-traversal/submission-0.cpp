/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;
        if (root == nullptr) {
            return output;
        }
        
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* popped_node = s.top();
            s.pop();

            output.push_back(popped_node->val);

            if (popped_node->right != nullptr) {
                s.push(popped_node->right);
            }

            if (popped_node->left != nullptr) {
                s.push(popped_node->left);
            }
        }
        
        return output;
    }
};