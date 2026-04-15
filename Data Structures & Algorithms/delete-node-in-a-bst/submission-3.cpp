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
    TreeNode* InorderSuccessor(TreeNode* root){
        if(root == nullptr){
            return nullptr;
        }
        while(root->left != nullptr){
            root = root->left;
        }
        return root;
    }
    TreeNode* deletedfs(TreeNode* root,int key){
        if(root == nullptr){
            return root;
        }
        // if(root->val == key){
        //     //delete this node
        //     root = root->right;
        // }
        if(key > root->val){
            root->right = deletedfs(root->right,key);
        }else if(key < root->val){
            root->left = deletedfs(root->left,key);
        }else{
            if(root->left == nullptr && root->right == nullptr){
                //no children
                delete root;
                return nullptr;
            }
            if(root->left != nullptr && root->right == nullptr){
                // left children , no right children
                TreeNode* temp = root;
                // delete root;
                return temp->left;
            }
            if(root->left == nullptr && root->right != nullptr){
                // right children , no left children
                TreeNode* temp = root;
                // delete root;
                return temp->right;
            }
            if(root->left != nullptr && root->right != nullptr){
                // 2 children case
                // delete root;
                TreeNode* is = InorderSuccessor(root->right);
                root->val = is->val;
                root->right = deletedfs(root->right,is->val);
                return root;
            }

        }
        return root;

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        root = deletedfs(root,key);
        return root;
    }
};