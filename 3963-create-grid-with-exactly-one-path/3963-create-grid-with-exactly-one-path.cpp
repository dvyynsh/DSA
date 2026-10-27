class Solution {
public:
    vector<string> createGrid(int m, int n) {

        // Step 1: Fill every cell with obstacle
        vector<string> grid(m, string(n, '#'));

        // Step 2: Make first row free
        for (int j = 0; j < n; j++) {
            grid[0][j] = '.';
        }

        // Step 3: Make last column free
        for (int i = 0; i < m; i++) {
            grid[i][n - 1] = '.';
        }

        return grid;
    }
};