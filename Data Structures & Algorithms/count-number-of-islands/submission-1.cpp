#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int num_islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Step 1: The Helicopter Scan
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // If we find unvisited land...
                if (grid[r][c] == '1') {
                    num_islands++; // We found a new island!
                    
                    // Step 2: Trigger DFS to "sink" this entire island
                    sinkIslandDFS(grid, r, c, rows, cols);
                }
            }
        }
        
        return num_islands;
    }

private:
    void sinkIslandDFS(vector<vector<char>>& grid, int r, int c, int rows, int cols) {
        // 1. BOUNDS CHECKING (The most important lines in matrix problems)
        // If we step off the edge of the map, or if we hit water ('0'), stop immediately.
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') {
            return;
        }
        
        // 2. SINK THE LAND (Mark as visited)
        grid[r][c] = '0';
        
        // 3. EXPLORE ALL 4 DIRECTIONS
        sinkIslandDFS(grid, r - 1, c, rows, cols); // Up
        sinkIslandDFS(grid, r + 1, c, rows, cols); // Down
        sinkIslandDFS(grid, r, c - 1, rows, cols); // Left
        sinkIslandDFS(grid, r, c + 1, rows, cols); // Right
    }
};