class Solution {
public:
    int countValidPrefixes(string s) {
        int n = s.size();
        int ans = 0;
        int one = 0, zero = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                one++;
            }
            else{
                zero++;
            }

            if(abs(one-zero)==1 || abs(one-zero)==0){
                ans++;
            }
        }
        return ans;
    }
};