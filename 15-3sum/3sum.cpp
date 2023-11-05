class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Approch 2 -> HASHSING
        /*
        int n=nums.size();
        set<vector<int>>unqTriplates;
        for(int i=0;i<n-1;i++)
        {
            set<int>hashSet;
            for(int j=i+1;j<n;j++)
            {
                int thirdEle=-(nums[i]+nums[j]);
                // Third Element is Present
                if(hashSet.find(thirdEle)!=hashSet.end())
                {
                    // Create Triplate
                    vector<int>triplate={nums[i],nums[j],thirdEle};
                    // Sort Triplate
                    sort(triplate.begin(),triplate.end());
                    // Push into UnqTriplates set
                    unqTriplates.insert(triplate);
                }
                // Insert the j'th element into hashSet
                hashSet.insert(nums[j]);
            }
        }
        vector<vector<int>>ans(unqTriplates.begin(),unqTriplates.end());
        // sort(ans.begin(),ans.end());
        return ans;
        // Time Complexity-> O(N^2 Log(K)) K-> Number of Unique Triplates
        // Space Complexity -> O(2*K)
        */
        // 2 Pointer's Approch
        // Sort the Array
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            continue;
            int j=i+1;
            int k=n-1;
            // 2 Pointer's Game
            while(j<k)
            {
                // Calculate Sum
                int sum=nums[i]+nums[j]+nums[k];
                // <0 -> Need to Increase
                if(sum<0)
                j++;
                // >0 -> Need to Decrease
                else if(sum>0)
                k--;
                // Equal
                else
                {
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1])
                    j++;
                    while(j<k && nums[k]==nums[k+1])
                    k--;
                }
            }
        }
        return ans;
    }
};