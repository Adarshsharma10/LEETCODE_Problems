class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,int> map;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            map[nums[i]]=i;
        }

        for(int i=0;i<n;i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int target = -1 * nums[i];
            for(int j = i+1;j<n;j++){
                if(j > i + 1 && nums[j] == nums[j-1]){
                    continue;
                }
                int var = target - nums[j];
                if(map.count(var) && map[var]>j){
                    ans.push_back({-1*target, nums[j], var});
                }
            }
        }
        return ans;
    }
};