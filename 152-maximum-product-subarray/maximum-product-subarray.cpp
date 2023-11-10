class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // APPROCH 1 -> PREFIX & SUFFIX
        /*
        int pre=1;
        int suf=1;
        int prod=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            // Previous Element was 0 -> Reset pre & suf
            if(pre==0)
            pre=1;
            if(suf==0)
            suf=1;
            // Calculate pre &suf
            pre*=nums[i];
            suf*=nums[n-1-i];

            // Calculate Max Subarray Product
            prod=max(prod,max(pre,suf));
        }
        return prod;
        */
        // APPROCH 2 -> KADANE'S ALGORITHM (EXTENSION)
        int prod1=nums[0],prod2=nums[0],ans=nums[0];

        for(int i=1;i<nums.size();i++){
            int temp=max({prod1*nums[i],prod2*nums[i],nums[i]});
            prod2=min({prod1*nums[i],prod2*nums[i],nums[i]});
            prod1=temp;
            ans=max(ans,prod1);
        }
        return ans;
    }
};