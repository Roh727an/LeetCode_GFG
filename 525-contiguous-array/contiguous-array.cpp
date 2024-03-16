class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        int sum=0,len=0;
        for(int i=0;i<nums.size();i++){
            sum+= nums[i]==0?-1:1;
            // Get a subarry with equal 1 & 0
            if(sum==0)
            {
                len=i+1;
            }
            // Encounter a sum that has encountered before
            else if(mp.find(sum)!=mp.end()){
                // Get the maximum stored
                len=max(len,i-mp[sum]);
            }
            // Map it
            else{
                mp[sum]=i;
            }
        }
        return len;
    }
};