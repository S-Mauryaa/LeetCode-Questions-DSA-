class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for(int  i=1;i<nums.size();i++){
            int j=i;
            while(j>=1 && nums[j]<nums[j-1])
             {
            swap(nums[j], nums[j - 1]);
            j--;
        }
        }
        int n = nums.size();
int mid = n / 2;

return nums[mid];

    }
};