class Solution {
public:
    int maxElement(vector<int>& nums)
    {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        return maxi;
    }
    int calculate(vector<int>& nums, int div){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < div || (nums[i]%div!=0))
            sum+=1;
            sum+=(nums[i]/div);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans=INT_MAX;
        int maxi=maxElement(nums);
        // Linear Search
        /*
        for(int i=1;i<=maxi;i++){
            int div=calculate(nums,i);
            if(div<=threshold)
            ans=min(i,ans);
        }
        */
        // Binary Search
        int s=1;
        int e=maxi;
        while(s<=e){
            int mid=(s+e)/2;
            int div=calculate(nums,mid);
            // Gets Smaller _> Fiind The minimum -> Left Part
            if(div<=threshold){
                e=mid-1;
                ans=min(ans,mid);
            }
            // Move Right
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};