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
    unordered_map<int,int> idx;
    int preIndex = 0;
    TreeNode* Helper(vector<int>& preorder, vector<int>& inorder , int inStart, int inEnd){
        if(inStart > inEnd){
            return nullptr;
        }
        int rootval = preorder[preIndex];
        preIndex++;
        TreeNode* root = new TreeNode(rootval);
        int mid = idx[rootval];

        root->left = Helper(preorder,inorder,inStart,mid-1);
        root->right = Helper(preorder,inorder,mid+1,inEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //if we take root from preorder 
        // find it in the inorder then element next to this root in the 
        // inorder is its root 
        /*
        first element of preorder is root 
        finding it in inorder , everything left to the root in this inorder
        is left of binary tree and everything right is right
        */
        
        for(int i=0;i<inorder.size();i++){
            idx[inorder[i]] = i;
        }
        return Helper(preorder,inorder,0,inorder.size()-1);
    }
};
