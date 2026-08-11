class Solution {
    unordered_map<TreeNode*, TreeNode*> parentMap;
    void buildParentMap(TreeNode* node, TreeNode* parent) {
        if (node == nullptr) return;
        if (parent != nullptr) {
            parentMap[node] = parent;
        }
        
        buildParentMap(node->left, node);
        buildParentMap(node->right, node);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildParentMap(root, nullptr);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        
        q.push(target);
        visited.insert(target);
        
        int current_distance = 0;

        while (!q.empty()) {
            if (current_distance == k) {
                break; 
            }
            
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();
                
                if (current->left != nullptr && visited.find(current->left) == visited.end()) {
                    q.push(current->left);
                    visited.insert(current->left);
                }
                
                if (current->right != nullptr && visited.find(current->right) == visited.end()) {
                    q.push(current->right);
                    visited.insert(current->right);
                }
                
                if (parentMap.find(current) != parentMap.end() && visited.find(parentMap[current]) == visited.end()) {
                    q.push(parentMap[current]);
                    visited.insert(parentMap[current]);
                }
            }
            current_distance++;
        }
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        
        return result;
    }
};