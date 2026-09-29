class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if ((n + m - 1) % 2)
            return false;

        if (grid[0][0] == ')')
            return false;

        int maxBal = n + m;

        vector<vector<vector<bool>>> dp(
            n,
            vector<vector<bool>>(
                m,
                vector<bool>(maxBal + 1, false)
            )
        );

        // Start with '('
        dp[0][0][1] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i == 0 && j == 0)
                    continue;

                for (int bal = 0; bal <= maxBal; bal++) {

                    // Balance after taking current cell
                    int prevBal;

                    if (grid[i][j] == '(')
                        prevBal = bal - 1;
                    else
                        prevBal = bal + 1;

                    if (prevBal < 0)
                        continue;

                    // From top
                    if (i > 0 && dp[i - 1][j][prevBal])
                        dp[i][j][bal] = true;

                    // From left
                    if (j > 0 && dp[i][j - 1][prevBal])
                        dp[i][j][bal] = true;
                }
            }
        }

        return dp[n - 1][m - 1][0];
    }
};