// 0   -> water 
// +ve -> island
// we going to use DFS


class Solution {
public:
    long long dfs(int i, int j,
                  vector<vector<int>>& grid,
                  vector<vector<bool>>& visited) {

        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[0].size() ||
            visited[i][j] ||
            grid[i][j] == 0)
            return 0;

        visited[i][j] = true;

        return (long long)grid[i][j]
             + dfs(i - 1, j, grid, visited)
             + dfs(i + 1, j, grid, visited)
             + dfs(i, j - 1, grid, visited)
             + dfs(i, j + 1, grid, visited);
    }

    int countIslands(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (!visited[i][j] && grid[i][j] != 0) {

                    long long islandSum = dfs(i, j, grid, visited);

                    if (islandSum % k == 0)
                        ans++;
                }
            }
        }

        return ans;
    }
};