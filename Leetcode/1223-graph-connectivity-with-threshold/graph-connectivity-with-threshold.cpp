class Solution {
    vector<int> parent;
    vector<int> rank;

    // Find function with path compression
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        // Path compression: point the node directly to the root
        return parent[i] = find(parent[i]);
    }

    void union_set(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else if (rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } else {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
        }
    }

public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i; 
        }
        for (int z = threshold + 1; z <= n; z++) {
            for (int m = 2 * z; m <= n; m += z) {
                union_set(z, m);
            }
        }

        vector<bool> result;
        result.reserve(queries.size());
        
        for (const auto& q : queries) {
            result.push_back(find(q[0]) == find(q[1]));
        }

        return result;
    }
};