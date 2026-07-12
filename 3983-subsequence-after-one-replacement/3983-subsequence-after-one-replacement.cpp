class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int i = 0,j = 0;
        for(auto it : t){
            if(s[i]==it) i++;
            i = max(i,j+1);
            if(s[j]==it) j++;
            if(i == n || j ==n) return true;
        }
        return false;
    }
};