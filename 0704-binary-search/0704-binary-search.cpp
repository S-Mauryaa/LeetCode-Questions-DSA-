class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int hi=nums.size()-1;
        while(low<=hi){
            int mid=(hi+low)/2;
            if(nums[mid]==target) return mid;
            else  if(nums[mid]>target) hi=mid-1;
            else low=mid+1;

        }
        return -1;
        }
        
    
};