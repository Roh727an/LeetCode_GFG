class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // APPROCH -> HASHMAP
        /*
        int n=nums.size();
        // Store the Frequency of Elements
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<int>ans;
        for(auto it:mp)
        {
            if(it.second > n/3 )
            ans.push_back(it.first);
        }
        return ans;
        */
        // Bayer Moore's Vooting Algorithm Extension
        int cnt1=0,cnt2=0,ele1=INT_MAX,ele2=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt1==0 && nums[i]!=ele2)
            {
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=ele1)
            {
                cnt2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1)
            cnt1++;
            else if(nums[i]==ele2)
            cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        // Manually Check
        cnt1=0;
        cnt2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ele1)
            cnt1++;
            else if(nums[i]==ele2)
            cnt2++;

        }
        vector<int>ans;
        if(cnt1> nums.size()/3)
        ans.push_back(ele1);
        if(cnt2> nums.size()/3)
        ans.push_back(ele2);

        return ans;
    }
};