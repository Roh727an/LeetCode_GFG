class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int distinct_element_index=0;
        int iteration_index=0;
        while(iteration_index<nums.size())
        {
            // If distinct ELement Found
            if(nums[distinct_element_index]!=nums[iteration_index])
            {
                nums[distinct_element_index+1]=nums[iteration_index];
                // Update Distinct ELement
                distinct_element_index++;
            }
            // Update iteration index
            else
            iteration_index++;
        }
        return  distinct_element_index+1;
    }
};