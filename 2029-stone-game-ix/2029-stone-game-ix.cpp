class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for(int i=0;i<n;i++){
            if(stones[i]%3==0){
                cnt0++;
            }
            else if(stones[i]%3==1){
                cnt1++;
            }
            else{
                cnt2++;
            }
        }
        if(cnt0&1) cnt0 = 1;
        else cnt0 = 0;
        
        if(cnt0 == 0){
            if(cnt1 >= 1 && cnt2 >= 1) return true;
            else return false;
        }
        else{
            if(abs(cnt1 - cnt2) > 2) return true;
            else return false;
        }
    
    }
};