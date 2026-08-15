class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int t_xor = 0;
        int zero = 0;
        for(int i=0;i<n;i++){
            t_xor^=nums[i];
            if(nums[i]==0){
                zero++;
            }
        }
        if(zero==n){
            return 0;
        }
        else if(t_xor == 0){
            return n-1;
        }
        return n;
    }
};