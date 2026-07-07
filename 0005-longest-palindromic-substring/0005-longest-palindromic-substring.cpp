class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        int start = 0, maxLength = 1;

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                int currentLength = right - left + 1;
                if (currentLength > maxLength) {
                    start = left;
                    maxLength = currentLength;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            expandAroundCenter(i, i);
            expandAroundCenter(i, i + 1);
        }

        return s.substr(start, maxLength);
    }
};