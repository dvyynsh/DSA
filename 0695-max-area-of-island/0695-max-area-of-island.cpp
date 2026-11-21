// In this problem rather than like prev problem 200 we incremented after exploring island
// But here we want after exploring island dfs should say i explores 4 cells
// DFS should return Area


class Solution {
public:

    int dfs(vector<vector<int>>& grid, int i, int j) {
        // Base Case
        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[0].size() ||
            grid[i][j] == 0)
            return 0;

        // Mark as visited
        grid[i][j] = 0;

        // Current cell (1)
        // + Area from all 4 directions
        return 1
             + dfs(grid, i + 1, j)   // Down
             + dfs(grid, i - 1, j)   // Up
             + dfs(grid, i, j + 1)   // Right
             + dfs(grid, i, j - 1);  // Left
    }



    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};