class Solution {
public:
    // Parse an expression containing unions
    set<string> parseExpression(string &s, int &i) {
        set<string> result = parseTerm(s, i);

        while (i < s.size() && s[i] == ',') {
            i++; // skip ','
            set<string> next = parseTerm(s, i);

            result.insert(next.begin(), next.end());
        }

        return result;
    }

    // Parse concatenation of multiple factors
    set<string> parseTerm(string &s, int &i) {
        set<string> result = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> factor = parseFactor(s, i);

            set<string> temp;

            for (const string &a : result) {
                for (const string &b : factor) {
                    temp.insert(a + b);
                }
            }

            result = temp;
        }

        return result;
    }

    // Parse a single letter or {...}
    set<string> parseFactor(string &s, int &i) {
        if (islower(s[i])) {
            return {string(1, s[i++])};
        }

        // s[i] == '{'
        i++; // skip '{'

        set<string> result = parseExpression(s, i);

        i++; // skip '}'

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> result = parseExpression(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};