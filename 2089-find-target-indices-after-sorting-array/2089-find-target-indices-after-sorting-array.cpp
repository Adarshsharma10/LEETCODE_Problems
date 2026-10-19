class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = count(nums.begin(),nums.end(),target);
        if(cnt==0) return {} ;
        sort(nums.begin(),nums.end());
        int it = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        vector<int> ans;
        while(cnt>0){
            ans.push_back(it++);
            cnt--;
        }
        return ans;
    }
};