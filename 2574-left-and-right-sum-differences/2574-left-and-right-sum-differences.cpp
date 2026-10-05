class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int totalSum = 0;

        // Calculate total sum
        for (int num : nums) {
            totalSum += num;
        }

        vector<int> answer;

        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Elements to the right
            int rightSum = totalSum - leftSum - nums[i];

            // Difference
            answer.push_back(abs(leftSum - rightSum));

            // Add current element to left sum
            leftSum += nums[i];
        }

        return answer;
    }
};