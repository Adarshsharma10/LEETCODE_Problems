class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int totalempty = 0;
        int left = 0, right = 0;
        int L = 0,R=0;
        for(int i=0;i<n;i++){
            if(i<n/2){
                if(num[i]=='?'){
                    totalempty++;
                    L++;
                }
                else{
                    left+=num[i]-'0';
                }
            }
            else{
                if(num[i]=='?'){
                    totalempty++;
                    R++;
                }
                else{
                    right+=num[i]-'0';
                }
            }
        }

        if(totalempty&1){
            return true;
        }

        return (left - right) != (R - L) / 2 * 9;
        
    }
};