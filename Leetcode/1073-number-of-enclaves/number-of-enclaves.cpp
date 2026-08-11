class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int rows, int cols) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0) {
            return;
        }
        
        // Mark the cell as visited by turning it into water (0)
        grid[i][j] = 0; 
        
        // Traverse all 4 directions recursively
        dfs(grid, i + 1, j, rows, cols); // Down
        dfs(grid, i - 1, j, rows, cols); // Up
        dfs(grid, i, j + 1, rows, cols); // Right
        dfs(grid, i, j - 1, rows, cols); // Left
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Step 1: Walk the perimeter of the grid. 
        // If we find a '1', launch a DFS to sink the entire connected island.
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // If we are on the top, bottom, left, or right edge
                if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                    if (grid[i][j] == 1) {
                        dfs(grid, i, j, rows, cols);
                    }
                }
            }
        }
        
        // Step 2: Count what's left. 
        // Any '1' remaining in the grid is an enclave because the DFS couldn't reach it.
        int enclaves = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    enclaves++;
                }
            }
        }
        
        return enclaves;
    }
};