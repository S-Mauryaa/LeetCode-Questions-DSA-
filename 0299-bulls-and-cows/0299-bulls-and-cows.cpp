class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;

        vector<int> secretCount(10, 0);
        vector<int> guessCount(10, 0);

        // Step 1: Find bulls
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } 
            else {
                secretCount[secret[i] - '0']++;
                guessCount[guess[i] - '0']++;
            }
        }

        // Step 2: Find cows
        for (int digit = 0; digit <= 9; digit++) {
            cows += min(secretCount[digit], guessCount[digit]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};