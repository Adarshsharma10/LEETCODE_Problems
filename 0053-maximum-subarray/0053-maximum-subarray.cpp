class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = INT_MIN;
        int curr_sum = 0;
        int cnt = 0;
        int maxi_neg = INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                cnt++;  
            }
            curr_sum+=nums[i];
            if(curr_sum<0){
                curr_sum=0;
            }
            max_sum=max(max_sum,curr_sum);
        }
        if(cnt==n){
            int ans = *max_element(nums.begin(),nums.end());
            return ans;
        }
        return max_sum;
    }
};