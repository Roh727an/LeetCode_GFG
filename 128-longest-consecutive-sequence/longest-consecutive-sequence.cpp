class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // // SORT THE ARRAY APPROCH
        // // Base Case
        // if(nums.size()==0 )
        // return 0;
        // if(nums.size()==1)
        // return 1;

        // sort(nums.begin(),nums.end());
        // int len=1;
        // int lastSmaller=INT_MIN;
        // int cnt=0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(lastSmaller==nums[i]-1)
        //     {
        //         cnt++;
        //         lastSmaller=nums[i];
        //     }
        //     else if(lastSmaller!=nums[i])
        //     {
        //         cnt=1;
        //         lastSmaller=nums[i];
        //     }
        //     len=max(len,cnt);
        // }
        // return len;
        // SET APPROCH
        int N=nums.size();
        if(N==0 )
        return 0;
        int len=INT_MIN;
        int cnt=0;
        int ele;
        unordered_set<int>st;
        // Put all Elements into Set DS
        for(int i=0;i<N;i++)
        {
            st.insert(nums[i]);
        }
        // Pick & Element & Search in DS
        for(auto it:st)
        {
            // If it is a Starting Point
            if(st.find(it-1)==st.end())
            {
                cnt=1;
                ele=it;
                // Calculate the LEngth of Sequence
                while(st.find(ele+1)!=st.end())
                {
                    ele=ele+1;
                    cnt++;
                }
                // Update length
                len=max(len,cnt);
            }
        }
        return len;
    }
};