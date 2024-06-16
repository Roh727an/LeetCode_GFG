class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long int currentSum = 1; // Tracks the smallest number that cannot be formed
        int patches = 0, index = 0;   // Pathches to keep track of the patch and Index to iterate through the nums array

        while (currentSum <= n)
        {
            // If the current number in nums is within the range and can be added to currentSum
            if (index < nums.size() && nums[index] <= currentSum)
            {
                currentSum += nums[index];; // Include nums[index] in the range
                index++;
            }
            else
            {
                // Add a patch (currentSum itself) to cover the range up to currentSum * 2 - 1
                currentSum += currentSum;
                patches++;
            }
        }
        return patches;
    }
};