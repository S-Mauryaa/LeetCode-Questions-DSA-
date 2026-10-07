class Solution {
public:

    bool isValid(string s) {
        int balance = 0;

        for (char c : s) {

            if (c == '(') {
                balance++;
            }
            else if (c == ')') {
                balance--;
            }

            if (balance < 0) {
                return false;
            }
        }

        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;

        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {

            int size = q.size();

            // Process one BFS level
            while (size--) {

                string curr = q.front();
                q.pop();

                // If valid, this is minimum removal level
                if (isValid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }

                // Don't generate next level
                // once valid strings are found
                if (found) {
                    continue;
                }

                // Remove one character
                for (int i = 0; i < curr.size(); i++) {

                    // Only remove parentheses
                    if (curr[i] != '(' && curr[i] != ')') {
                        continue;
                    }

                    string next = curr.substr(0, i)
                                + curr.substr(i + 1);

                    if (visited.find(next) == visited.end()) {

                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            // We found answers at this level
            if (found) {
                break;
            }
        }

        return ans;
    }
};