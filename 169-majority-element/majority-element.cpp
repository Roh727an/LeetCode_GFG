class Solution {
public:
    int majorityElement(vector<int>& nums) {
    //     // HASHMAP
    //     unordered_map<int,int>mp;
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         mp[nums[i]]++;
    //     }
    //     for(auto i:mp)
    //     {
    //         if(i.second>nums.size()/2)
    //         return i.first;
    //     }
    //     return -1;

        // MOORE'S VOOTING ALGORITHM
        int n=nums.size();
        int ele;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            // Reset 
            if(cnt==0)
            {
                cnt=1;
                ele=nums[i];
            }
            else if(ele==nums[i])
            cnt++;
            else
            cnt--;
        }
        return ele;
    }

};