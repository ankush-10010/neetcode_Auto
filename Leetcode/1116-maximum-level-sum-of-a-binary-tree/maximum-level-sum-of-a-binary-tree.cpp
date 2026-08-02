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
    int maxLevelSum(TreeNode* root) {
        // int maxSum = INT_MIN;
        pair<int,int> p = {INT_MIN,0};
        queue<TreeNode*>q;
        q.push(root);
        int l = 0;
        while(!q.empty()){
            l++;
            int levelSize = q.size();
            int currentSum = 0;
            for(int i=0;i<levelSize;i++){
                TreeNode* currElement = q.front();
                int currVal = currElement->val;
                currentSum+=currVal;
                q.pop();
                if(currElement->left){
                    q.push(currElement->left);
                }
                if(currElement->right){
                    q.push(currElement->right);
                }
            }
            if(p.first < currentSum){
                p = {currentSum,l};
            }
        }

        return p.second;
    }
};