class Solution {
    long long MOD = 1e9 + 7;
    vector<vector<long long>> table;

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        table.resize(n + 1, vector<long long>(n + 1, 1));
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
            }
        }
        
        return (int)((dfs(nums) - 1 + MOD) % MOD);
    }

private:
    long long dfs(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;
        
        vector<int> l, r;
        int root = nums[0];
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < root) {
                l.push_back(nums[i]);
            } else {
                r.push_back(nums[i]);
            }
        }
        
        long long lWays = dfs(l) % MOD;
        long long rWays = dfs(r) % MOD;
        
        long long comb = table[l.size() + r.size()][l.size()];
        
        return (((comb * lWays) % MOD) * rWays) % MOD;
    }
};