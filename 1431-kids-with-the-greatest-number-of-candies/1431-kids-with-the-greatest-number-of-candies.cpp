class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = 0;
        // Find maximum
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] > maxCandies) {
                maxCandies = candies[i];
            }
        }
        // Create result with same size
        vector<bool> result(candies.size());
        // Fill result
        for (int i = 0; i < candies.size(); i++) {
            result[i] = (candies[i] + extraCandies >= maxCandies);
        }
        return result;
    }
};