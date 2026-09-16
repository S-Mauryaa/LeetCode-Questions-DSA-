class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //  Easy method
        // int n=nums.size();
        // vector<bool> check(n+1,false);
        // for(int i=0;i<n;i++){
        //     int ele=nums[i];
        //     check[ele]=true;
        // }    
        // for(int i=0;i<=n;i++){
        //     if(check[i]==false) return i;
        //     }
        //     return 0;

        // using Cyclic Search
        int n=nums.size();
        int i=0;
        while(i<n){
            int correctIdx=nums[i];
            if(correctIdx==i || nums[i]==n) i++;
            else swap(nums[i],nums[correctIdx]);
        }   
        for(int i=0;i<n;i++){
            if(nums[i]!=i)return i;
        }
        return n;

        // sortest method
        // int actualsum=n*(n+1)/2;
        // int sum=0;
        // for(int i=0;i<n;i++){
        //     sum+=nums[i];
        // }
        // return actualsum-sum;

    }

};