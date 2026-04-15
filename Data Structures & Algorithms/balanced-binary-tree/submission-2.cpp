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
    int height(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int rightH=0;
        int leftH=0;
        if(root->left!=nullptr){
            leftH=height(root->left);
        }
        if(root->right!=nullptr){
            rightH=height(root->right);
        }
        return 1+max(leftH,rightH);
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        isBalanced(root->left);
        isBalanced(root->right);

        int heightleft=height(root->left);
        int heightright=height(root->right);
        if(abs(heightleft-heightright)>1){
            return false;
        }
        if(!isBalanced(root->left) || !isBalanced(root->right)){
            return false;
        }
        return true;
    }
};
