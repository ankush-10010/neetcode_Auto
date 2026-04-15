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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr){
            return true;
        }
        if (p == nullptr || q == nullptr) {
            return false;
        }
        if(p->left!=nullptr && q->left!=nullptr){
        isSameTree(p->left,q->left);}
        if(p->right!=nullptr && q->right!=nullptr){
        isSameTree(p->right,q->right);}

        if(!isSameTree(p->left,q->left) || !isSameTree(p->right,q->right)){
            return false;
        }

        if(p->val!=q->val){
            return false;
        }
        // if(p->right->val!=q->right->val){
        //     return false;
        // }
        return true;
    }
};
