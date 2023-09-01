class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 1.Create a Deque(Stor index Not Value)**
        deque<int>dq;
        vector<int>ans;
        // 2.Traverse Array & Check-
        for(int i=0;i<nums.size();i++)
        {
            // a.If Deque has Elements Out of Bound then Pop from Front
            if(!dq.empty()&& dq.front()==i-k)
            {
                dq.pop_front();
            }

            // b.Pop Elements from Deque till Current element is Greater Than dq Back
            while(!dq.empty() && nums[i] > nums[dq.back()])
            {
                dq.pop_back();
            }
            // c.Insert current Index into Deque
            dq.push_back(i);

            if(i>=k-1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
         return ans;
    }
};