class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v; 
        int max_diff = -1;
        
        for (int i = 0; i < n; i++) {
            int mini = INT_MAX;
            int maxi = INT_MIN;
            int val = nums[i];
            
            if (val == 0) {
                mini = 0;
                maxi = 0;
            }
            
            while (val > 0) {
                mini = min(mini, val % 10);
                maxi = max(maxi, val % 10);
                val = val / 10;
            }
            
            int diff = maxi - mini;
            v.push_back({nums[i], diff});
            max_diff = max(max_diff, diff);
        }
        
        int sum = 0;
        for (auto& it : v) {
            if (it.second == max_diff) {
                sum += it.first;
            }
        }
        
        return sum;
    }
};