class Solution {
private:
    long long dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Out of bounds or already visited or water (0)
        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] || grid[r][c] == 0) {
            return 0;
        }
        
        visited[r][c] = true;
        long long current_sum = grid[r][c];
        
        // 4-directional movement: up, down, left, right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; ++i) {
            current_sum += dfs(r + dr[i], c + dc[i], grid, visited);
        }
        
        return current_sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int valid_islands_count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    long long total_value = dfs(i, j, grid, visited);
                    if (total_value % k == 0) {
                        valid_islands_count++;
                    }
                }
            }
        }
        
        return valid_islands_count;
    }
};