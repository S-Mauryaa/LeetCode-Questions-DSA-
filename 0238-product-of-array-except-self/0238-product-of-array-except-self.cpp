class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // Normal method

    //     int product =1;
    //     int p2=1;
    //     int noz=0;
    //     for(int i=0;i<n;i++){
    //         if(nums[i]==0) noz++;
    //         product*=nums[i];
    //         if(nums[i]!=0) p2*=nums[i];
    //     }
    //     if(noz>1) p2=0;
    //     for(int i=0;i<n;i++){
    //         if(nums[i]==0) nums[i]=p2;
    //         else nums[i]=product/nums[i];
    //     }
    // return nums;

    // prefix Sum
        vector<int> pre(n);
        vector<int> suf(n);
        vector<int> ans(n);
        // pefix Product array
        int p=nums[0];
        pre[0]=1;
        for(int i=1;i<n;i++){
            pre[i]=p;
            p*=nums[i];
        }
        // suffix Product array
        p=nums[n-1];
        suf[n-1]=1;
        for(int i=n-2;i>=0;i--){
            suf[i]=p;
            p*=nums[i];
        }
        // Ans array
        for(int i=0;i<n;i++){
            ans[i]=pre[i]*suf[i];
        }
        return ans;
    }
};