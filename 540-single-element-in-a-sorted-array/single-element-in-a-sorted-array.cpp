class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int s=0,e=n-1,mid;
        while(s<=e){
            mid=s+(e-s)/2;
            if(s==e)
            return nums[mid];
            // Mid is Even Index
            else if(mid%2==0)
            {
                if(mid+1 < n && nums[mid]==nums[mid+1])
                s=mid+2;
                else
                e=mid;
            }
            // Mid is Odd Index
            else{
                if(mid-1 >=0  && nums[mid]==nums[mid-1])
                s=mid+1;
                else
                e=mid-1;
            }
        }
        return -1;
    }
};