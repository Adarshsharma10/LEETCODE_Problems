class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int r = n-1;
        int l = 0;
        int ans = INT_MIN;
        while(l<r){
            int dist = r-l;
            int heig = min(height[l],height[r]);
            ans = max(ans,dist*heig);
            if(height[l]>=height[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};