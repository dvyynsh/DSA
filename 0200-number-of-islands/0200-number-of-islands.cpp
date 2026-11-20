class Solution {
public:
    int rows, cols;

    void dfs(vector<vector<char>>& grid, int i, int j) {

        // Base Cases
        if (i < 0 || j < 0 || i >= rows || j >= cols)
            return;

        if (grid[i][j] == '0')
            return;

        // Mark as visited
        grid[i][j] = '0';

        // Explore 4 directions
        dfs(grid, i + 1, j); // Down
        dfs(grid, i - 1, j); // Up
        dfs(grid, i, j + 1); // Right
        dfs(grid, i, j - 1); // Left
    }

    int numIslands(vector<vector<char>>& grid) {

        rows = grid.size();
        cols = grid[0].size();

        int islands = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }

            }
        }

        return islands;
    }
};