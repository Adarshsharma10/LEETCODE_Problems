#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    unordered_set<string> result;

    void dfs(const string& s, int index, int balance, int left_rem, int right_rem, string current) {
        if (balance < 0) return;

        if (index == s.length()) {
            if (balance == 0 && left_rem == 0 && right_rem == 0) {
                result.insert(current);
            }
            return;
        }

        char ch = s[index];

        if (ch == '(') {
            if (left_rem > 0) {
                dfs(s, index + 1, balance, left_rem - 1, right_rem, current);
            }
            dfs(s, index + 1, balance + 1, left_rem, right_rem, current + ch);
        } else if (ch == ')') {
            if (right_rem > 0) {
                dfs(s, index + 1, balance, left_rem, right_rem - 1, current);
            }
            dfs(s, index + 1, balance - 1, left_rem, right_rem, current + ch);
        } else {
            dfs(s, index + 1, balance, left_rem, right_rem, current + ch);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int left_rem = 0, right_rem = 0;

        for (char ch : s) {
            if (ch == '(') {
                left_rem++;
            } else if (ch == ')') {
                if (left_rem > 0) left_rem--;
                else right_rem++;
            }
        }

        dfs(s, 0, 0, left_rem, right_rem, "");
        return vector<string>(result.begin(), result.end());
    }
};