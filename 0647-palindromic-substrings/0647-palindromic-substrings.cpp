class Solution {
public:
    bool func(string s){
        int n = s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-1-i]){
                return false;
            }
        }
        return true;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int k = 2;
        int ans = n;
        while(k<=n){
            for(int i = 0;i<n-k+1;i++){
                bool flag = func(s.substr(i,k));
                if(flag){
                    ans++;
                }
            }
            k++;
        }
        return ans;
    }
};