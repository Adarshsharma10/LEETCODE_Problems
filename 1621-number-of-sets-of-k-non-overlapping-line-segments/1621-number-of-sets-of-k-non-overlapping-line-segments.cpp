#include <vector>

class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        
        // dp[i][j]: ways to draw j segments using the first i points
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        
        // Base case: 1 way to draw 0 segments for any number of points
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 1;
        }
        
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= min(i - 1, k); ++j) {
                // Formula: 2 * dp[i-1][j] - dp[i-2][j] + dp[i-1][j-1]
                dp[i][j] = (2 * dp[i - 1][j] - dp[i - 2][j] + dp[i - 1][j - 1]) % MOD;
                
                // Handle negative modulo result in C++
                if (dp[i][j] < 0) {
                    dp[i][j] += MOD;
                }
            }
        }
        
        return dp[n][k];
    }
};