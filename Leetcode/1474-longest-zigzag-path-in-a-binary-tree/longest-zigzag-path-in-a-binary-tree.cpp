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
    void backtrack(TreeNode* root,bool isLeft,int score,int& maxScore){
        if(root == nullptr) return;
        maxScore = max(score,maxScore);
        if(isLeft){
            backtrack(root->left,false,score+1,maxScore);
            backtrack(root->right,true,1,maxScore);
        }else{
            backtrack(root->right,true,score+1,maxScore);
            backtrack(root->left,false,1,maxScore);
        } 
    }
    int longestZigZag(TreeNode* root) {
        int maxScore = 0;
        if(root == nullptr) return 0;
        backtrack(root->right,true,1,maxScore);
        backtrack(root->left,false,1,maxScore);
        return maxScore;
    }
};