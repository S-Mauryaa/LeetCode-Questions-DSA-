// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>ans(nums.size());
//         for(int i=0;i<n;i++){
//             int count=0;
//             for(int j=0;j<n;j++){
//                 if( nums[j]<nums[i]) count++;
//             }
//             ans[i]=count;
//         }
        
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        vector<int> result(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            result[i] = lower_bound(sorted.begin(), sorted.end(), nums[i]) 
                        - sorted.begin();
        }

        return result;
    }
};