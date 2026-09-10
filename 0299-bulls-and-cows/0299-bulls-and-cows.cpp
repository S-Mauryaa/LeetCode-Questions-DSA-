class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        int count[10] = {};

        for (int i = 0; i < secret.size(); i++) {
            int s = secret[i] - '0';
            int g = guess[i] - '0';

            if (s == g) {
                bulls++;
            }
            else {
                // If this guess digit has appeared in secret's
                // unmatched part, it forms a cow.
                if (count[g] > 0)
                    cows++;

                // If this secret digit has appeared in guess's
                // unmatched part, it forms a cow.
                if (count[s] < 0)
                    cows++;

                count[s]++;
                count[g]--;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};