class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int a = sum/9;
        char b = sum%9 + '0';
        string ans = "";
        if(sum>9*num) return "";
        bool flag = true;
        for(int i=0;i<num;i++){
            if(a>0){
                ans+="9";
                a--;
            }
            else if(flag){
                ans+=b;
                flag = false;
            }
            else{
                ans+="0";
            }
        }
        return ans;
    }
};