class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int dup = 0;
        for (int bit = 0; bit < 32; bit++) {
            // Check if I'th Bit is Set or Not & Count
            int orgSet = 0, arrSet = 0;
            for (int i = 0; i < nums.size(); i++) {
                if ((1 << bit) & i)
                    orgSet++;
                if ((1 << bit) & nums[i])
                    arrSet++;
            }
            // Unset the i'th Bit if the Number of 'th Bit is Greater than Org
            if (arrSet > orgSet)
                dup |=(1 << bit);
        }
        return dup;
    }
};