class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            map[numbers[i]]=i;
        }
        int idx1 = -1 , idx2 = -1;
        for(int i=0;i<n;i++){
            idx1 = i;
            int var = target - numbers[i];
            if(map.count(var) && map[var] != i){
                idx2 = map[var];
                break;
            }
            
        }
        return {idx1 + 1, idx2 + 1};
    }
};