class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int open = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open++;
            }
            else {
                // We found ')'
                // If next character is also ')',
                // together they form ")).
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++;
                }
                else {
                    // We have only one ')',
                    // so insert another ')'.
                    ans++;
                }
                // This "))" needs one "(".
                if (open > 0) {
                    open--;
                }
                else {
                    // No "(" available,
                    // so insert one.
                    ans++;
                }
            }
        }
        // Every remaining "(" needs "))".
        ans += open * 2;

        return ans;
    }
};