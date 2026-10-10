class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long totalOps = (long long)k1 + k2;
        vector<long long> count(100005, 0);
        long long maxDiff = 0;
        for (int i = 0; i < n; i++) {
            long long d = abs(nums1[i] - nums2[i]);
            count[d]++;
            maxDiff = max(maxDiff, d);
        }
        
        for (long long i = maxDiff; i > 0; i--) {
            if (count[i] == 0) continue;
            long long take = min(totalOps, count[i]);
            count[i] -= take;
            count[i - 1] += take;
            totalOps -= take;
            
            if (totalOps == 0) break;
        }
        long long ans = 0;
        for (long long i = 0; i <= maxDiff; i++) {
            if (count[i] > 0) {
                ans += count[i] * i * i;
            }
        }
        
        return ans;
    }
};