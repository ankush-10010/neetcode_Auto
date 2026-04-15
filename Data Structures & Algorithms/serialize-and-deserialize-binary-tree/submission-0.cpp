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

class Codec {
public:
    // string Serialisedresult = "";
    void dfs(TreeNode* root,string &s){
        if(root == nullptr){
            s+="N,";
            return;
        }
        s += to_string(root->val) + "," ;
        dfs(root->left,s);
        dfs(root->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // we will use the "," as separator
        // [1,2,3,null,null,4,5] => 123NN45
        string s;
        dfs(root,s);
        return s;
    }

    TreeNode* deserialiseDFS(queue<string> &q){
        if(q.front()=="N"){
            q.pop();
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(q.front()));
        q.pop();
        root->left = deserialiseDFS(q);
        root->right = deserialiseDFS(q);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string temp;
        for(char c : data){
            if(c==','){
                q.push(temp);
                temp.clear();
            }else{
                temp.push_back(c);
            }
        }

        return deserialiseDFS(q);
    }
};
