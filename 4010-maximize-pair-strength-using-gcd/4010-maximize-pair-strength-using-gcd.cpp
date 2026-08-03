class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MIN;
        for(int i=0;i<n;i++){
            for(int j = i+1 ; j<n;j++){
                long long m = 1LL*nums[i]*nums[j];
                long long gcd = __gcd(nums[i],nums[j]);
                long long compute = m/(gcd*gcd);
                ans = max(ans,compute);
            }
        }
        return ans;
    }
};