class Solution {
public:
    unordered_set<string> visited;
    string ans;

    void dfs(string node, int k) {
        for (int i = 0; i < k; ++i) {
            string edge = to_string(i);
            string password = node + edge; 
            
            if (visited.find(password) == visited.end()) {
                visited.insert(password);
                string next_node = password.substr(1);
                
                dfs(next_node, k);
                ans += edge; 
            }
        }
    }

    string crackSafe(int n, int k) {
        if (n == 1) {
            string res = "";
            for (int i = 0; i < k; ++i) res += to_string(i);
            return res;
        }
        string start_node = string(n - 1, '0');
        dfs(start_node, k);

        ans += start_node;
        
        return ans;
    }
};