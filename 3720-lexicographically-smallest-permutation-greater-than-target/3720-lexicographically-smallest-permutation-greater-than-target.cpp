class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        // cnt[c] = characters available in s
        // after matching target prefix.
        int cnt[26] = {};

        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
            cnt[target[i] - 'a']--;
        }

        // Start from the rightmost position.
        for (int i = n - 1; i >= 0; i--) {

            int x = target[i] - 'a';

            // Undo target[i], because we are going to
            // change the character at position i.
            cnt[x]++;

            // If any cnt is negative, then target[0..i-1]
            // cannot be formed from s.
            bool possible = true;

            for (int c = 0; c < 26; c++) {
                if (cnt[c] < 0) {
                    possible = false;
                    break;
                }
            }

            if (!possible)
                continue;

            // Find the smallest character greater than target[i].
            for (int c = x + 1; c < 26; c++) {

                if (cnt[c] > 0) {

                    cnt[c]--;

                    string ans = target.substr(0, i);
                    ans += char('a' + c);

                    // Put remaining characters in sorted order.
                    for (int k = 0; k < 26; k++) {
                        while (cnt[k] > 0) {
                            ans += char('a' + k);
                            cnt[k]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};