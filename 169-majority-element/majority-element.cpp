class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore's Voting ALgorithm
        int cnt=0;
        int ele;
        for(int i=0;i<nums.size();i++)
        {
            // Reset
            if(cnt==0)
            {
                cnt=1;
                ele=nums[i];
            }
            else if(nums[i]==ele)
            cnt++;
            else
            cnt--;
        }
        return ele;
    }
};