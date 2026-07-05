class Solution {
public:
    bool isPalindrome(string s) {
        int n= s.size();
        string m = "";
        for(int i=0;i<n;i++){
            if((65<=s[i] && s[i]<=90) || (97<=s[i] && s[i]<=122) || (48<=s[i] && s[i]<=57)){
                m.push_back(tolower(s[i]));
            }
        }
        for(int i=0;i<m.size()/2;i++){
            if(m[i]!=m[m.size()-1-i]){
                return false;
            }
        }
        return true;
    }
};