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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root==nullptr){
            return result;
        }
        queue<TreeNode*> Q;
        Q.push(root);

        while(!Q.empty()){
            vector<int> level;
            int levelsize=Q.size();
            for(int i=0 ; i<levelsize ; i++){
                TreeNode* curr=Q.front();
                level.push_back(curr->val);
                Q.pop();   
                if(curr->left!=nullptr){
                Q.push(curr->left);
            }
                if(curr->right!=nullptr){
                    Q.push(curr->right);
                }

                if(i==levelsize-1){
                    result.push_back(level[levelsize-1]);}
            } 
            
        }
        return result;
    }
};
