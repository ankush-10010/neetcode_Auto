class Solution {
    // Arrays to keep track of the DSU structures
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

    // Union function with union by rank
    void union_set(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        
        if (root_i != root_j) {
            // Attach the smaller tree under the taller tree
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
        // Initialize DSU. 1-indexed to match city labels up to n.
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i; 
        }

        // Connect all numbers that share a common divisor > threshold
        for (int z = threshold + 1; z <= n; z++) {
            // Connect z with all its multiples: 2z, 3z, 4z, etc.
            for (int m = 2 * z; m <= n; m += z) {
                union_set(z, m);
            }
        }

        // Answer the queries
        vector<bool> result;
        result.reserve(queries.size());
        
        for (const auto& q : queries) {
            // If they share the same root parent, there is a valid path!
            result.push_back(find(q[0]) == find(q[1]));
        }

        return result;
    }
};