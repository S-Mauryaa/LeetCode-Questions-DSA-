class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // Already sorted
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        // Cannot sort a string of length 2
        if (n == 2) {
            return -1;
        }

        // Check if one operation is sufficient
        string t = s;
        sort(t.begin() + 1, t.end());

        if (is_sorted(t.begin(), t.end())) {
            return 1;
        }

        t = s;
        sort(t.begin(), t.end() - 1);

        if (is_sorted(t.begin(), t.end())) {
            return 1;
        }

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // Three operations only when the first character
        // is the unique maximum AND the last is the unique minimum.
        if (s[0] == mx && s[n - 1] == mn &&
            count(s.begin(), s.end(), mx) == 1 &&
            count(s.begin(), s.end(), mn) == 1) {
            return 3;
        }

        return 2;
    }
};