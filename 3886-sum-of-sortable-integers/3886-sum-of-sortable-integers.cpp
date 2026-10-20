class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefm(n+1,0),suffmin(n+1,INT_MAX),cyc(n,0);
        for(int i=1;i<=n;i++){
            prefm[i]=max(prefm[i-1],nums[i-1]);
        }
        for(int i = n-1;i>=0;i--){
            suffmin[i]=min(suffmin[i+1],nums[i]);
        }
        for(int i=1;i<n;i++){
            cyc[i]=cyc[i-1]+(nums[i-1]>nums[i]);
        }

        int ans = 0;
        for(int k=1;k<=n;k++){
            if(n%k!=0){
                continue;
            }
            bool flag = true;
            for(int i=0;i<n;i+=k){
                int j = i+k-1;
                int cnt = cyc[j]-cyc[i] + (nums[j]>nums[i]);
                if(cnt>1){
                    flag=false;
                    break;
                }
                if(i>0 && prefm[i]>suffmin[i]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans+=k;
            }
        }
        return ans;
    }
};