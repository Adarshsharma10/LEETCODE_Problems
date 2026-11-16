class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            int n = s.size();
            string r="";
            for(int i=0;i<n;i+=k){
                int sum=0;
                for(int j=i;j<i+k && j<n;j++){
                    sum+=int(s[j]-'0');
                }
                r+=to_string(sum);
            }
            s=r;
        }
        return s;
    }
};